#include "mainwindow.h"

#include "display_window.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->lineEdit_rotation_x->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->lineEdit_rotation_y->setButtonSymbols(QAbstractSpinBox::NoButtons);
  ui->lineEdit_rotation_z->setButtonSymbols(QAbstractSpinBox::NoButtons);
  set_parameters_to_default();
  write_to_ui();
  readSettings();
}

void init_backgroud_color(double* array) {
  array[0] = 0.1;
  array[1] = 0.1;
  array[2] = 0.1;
}
void init_point_color(double* array) {
  array[0] = 0.0;
  array[1] = 1.0;
  array[2] = 1.0;
}
void init_line_color(double* array) {
  array[0] = 0.5;
  array[1] = 0.5;
  array[2] = 1.0;
}
void color_normalization(double* array) {
  for (int i = 0; i < 3; i++) {
    array[i] /= 255;
  }
}

void MainWindow::on_pushButton_apply_changes_clicked() {
  // sliders
  ui->display_window->my_data.background_color[0] =
      ui->backgroundColor_red->value();
  ui->display_window->my_data.background_color[1] =
      ui->backgroundColor_green->value();
  ui->display_window->my_data.background_color[2] =
      ui->backgroundColor_blue->value();
  ui->display_window->my_data.line_color[0] = ui->lineColor_red->value();
  ui->display_window->my_data.line_color[1] = ui->lineColor_green->value();
  ui->display_window->my_data.line_color[2] = ui->lineColor_blue->value();
  ui->display_window->my_data.point_color[0] = ui->vertColor_red->value();
  ui->display_window->my_data.point_color[1] = ui->vertColor_green->value();
  ui->display_window->my_data.point_color[2] = ui->vertColor_blue->value();
  color_normalization(ui->display_window->my_data.background_color);
  color_normalization(ui->display_window->my_data.line_color);
  color_normalization(ui->display_window->my_data.point_color);
  ui->display_window->my_data.line_width =
      ui->lineEdit_line_width->text().toInt();
  ui->display_window->my_data.point_size =
      ui->lineEdit_point_size->text().toInt();
  if (ui->qcombobox_typeProjection->currentText() == "parallel") {
    ui->display_window->my_data.projection_type = PARALLEL;
  } else {
    ui->display_window->my_data.projection_type = CENTRAL;
  }
  if (ui->qcombobox_displayVertices->currentText() == "none") {
    ui->display_window->my_data.point_type = NONE;
  } else if (ui->qcombobox_displayVertices->currentText() == "circle") {
    ui->display_window->my_data.point_type = CIRCLE;
  } else if (ui->qcombobox_displayVertices->currentText() == "square") {
    ui->display_window->my_data.point_type = SQUARE;
  }
  if (ui->qcombobox_edgesType->currentText() == "solid") {
    ui->display_window->my_data.line_type = SOLID;
  } else {
    ui->display_window->my_data.line_type = DASHED;
  }
  ui->display_window->update();
}

void MainWindow::on_pushButton_open_obj_file_clicked() {
  ui->display_window->my_data.path_to_file =
      QFileDialog::getOpenFileName(this, tr("Open .obj file"), "../../obj",
                                   tr(".obj Files (*.obj *.OBJ)"))
          .toStdString();

  if (ui->display_window->my_data.path_to_file.empty()) {
    QMessageBox::critical(this, tr("Error"), tr("Failed to open .obj file"));
    return;
  }

  set_model_transformations_to_zero();
  read_obj_file();
}

void MainWindow::set_model_transformations_to_zero() {
  ui->display_window->my_data.rotation[0] = 0;
  ui->display_window->my_data.rotation[1] = 0;
  ui->display_window->my_data.rotation[2] = 0;

  ui->display_window->my_data.rotation_display[0] = 0;
  ui->display_window->my_data.rotation_display[1] = 0;
  ui->display_window->my_data.rotation_display[2] = 0;

  ui->display_window->my_data.scale[0] = 10;
  ui->display_window->my_data.scale[1] = 10;
  ui->display_window->my_data.scale[2] = 10;

  ui->display_window->my_data.translation[0] = 0;
  ui->display_window->my_data.translation[1] = 0;
  ui->display_window->my_data.translation[2] = 0;

  ui->display_window->shape->angles[0] = 0;
  ui->display_window->shape->angles[1] = 0;
  ui->display_window->shape->angles[2] = 0;
  write_to_ui();
}

void MainWindow::read_obj_file() {
  ui->display_window->is_ready_to_draw = false;
  s21_clearShape(ui->display_window->shape);
  s21_zeroingShape(ui->display_window->shape);

  ui->textBrowser_name_of_file->setText(
      QString::fromUtf8(ui->display_window->my_data.path_to_file.c_str()));

  ui->display_window->my_data.name_of_file =
      ui->display_window->my_data.path_to_file.substr(
          ui->display_window->my_data.path_to_file.find_last_of("/\\") + 1);

  ui->textBrowser_name_of_file->setText(
      QString::fromUtf8(ui->display_window->my_data.name_of_file.c_str()));

  s21_initShape(ui->display_window->shape,
                ui->display_window->my_data.path_to_file.c_str());

  if (ui->display_window->shape->countV < 1 ||
      ui->display_window->shape->countVertexes < 1 ||
      ui->display_window->shape->countL < 1) {
    QMessageBox::critical(this, tr("Error"), tr("Incorrect .obj file"));
    ui->display_window->is_ready_to_draw = false;
    ui->display_window->update();
  } else {
    ui->display_window->is_ready_to_draw = true;

    ui->label_number_of_edges->setText(
        QString::number(ui->display_window->shape->countLines / 2));

    ui->label_number_of_vertices->setText(
        QString::number(ui->display_window->shape->countV));

    ui->display_window->my_data.name_of_model =
        ui->display_window->shape->modelName;

    if (ui->display_window->my_data.name_of_model.empty() == true) {
      ui->display_window->my_data.name_of_model =
          ui->display_window->shape->fileName;
    }

    ui->textBrowser_name_of_model->setText(
        QString::fromUtf8(ui->display_window->my_data.name_of_model.c_str()));

    ui->display_window->update();
  }
}

void MainWindow::write_to_ui() {
  ui->backgroundColor_red->setValue(
      ui->display_window->my_data.background_color[0] * 255);
  ui->backgroundColor_green->setValue(
      ui->display_window->my_data.background_color[1] * 255);
  ui->backgroundColor_blue->setValue(
      ui->display_window->my_data.background_color[2] * 255);
  ui->lineColor_red->setValue(ui->display_window->my_data.line_color[0] * 255);
  ui->lineColor_green->setValue(ui->display_window->my_data.line_color[1] *
                                255);
  ui->lineColor_blue->setValue(ui->display_window->my_data.line_color[2] * 255);
  ui->vertColor_red->setValue(ui->display_window->my_data.point_color[0] * 255);
  ui->vertColor_green->setValue(ui->display_window->my_data.point_color[1] *
                                255);
  ui->vertColor_blue->setValue(ui->display_window->my_data.point_color[2] *
                               255);
  ui->lineEdit_line_width->setText(
      QString::number(ui->display_window->my_data.line_width));
  ui->lineEdit_point_size->setText(
      QString::number(ui->display_window->my_data.point_size));
  ui->qcombobox_typeProjection->setCurrentIndex(
      ui->display_window->my_data.projection_type == PARALLEL ? 0 : 1);
  ui->qcombobox_edgesType->setCurrentIndex(
      ui->display_window->my_data.line_type == SOLID ? 0 : 1);
  if (ui->display_window->my_data.point_type == NONE) {
    ui->qcombobox_displayVertices->setCurrentIndex(0);
  } else if (ui->display_window->my_data.point_type == CIRCLE) {
    ui->qcombobox_displayVertices->setCurrentIndex(1);
  } else {
    ui->qcombobox_displayVertices->setCurrentIndex(2);
  }

  ui->lineEdit_rotation_x->setValue(
      ui->display_window->my_data.rotation_display[0]);
  ui->lineEdit_rotation_y->setValue(
      ui->display_window->my_data.rotation_display[1]);
  ui->lineEdit_rotation_z->setValue(
      ui->display_window->my_data.rotation_display[2]);

  ui->lineEdit_scale_x->setValue(ui->display_window->my_data.scale[0]);

  ui->lineEdit_translation_x->setValue(
      ui->display_window->my_data.translation[0]);
  ui->lineEdit_translation_y->setValue(
      ui->display_window->my_data.translation[1]);
  ui->lineEdit_translation_z->setValue(
      ui->display_window->my_data.translation[2]);
}

void MainWindow::set_parameters_to_default() {
  ui->display_window->my_data.number_of_edges = 0;
  ui->display_window->my_data.number_of_vertices = 0;

  ui->display_window->my_data.projection_type = PARALLEL;

  ui->display_window->my_data.line_type = SOLID;
  ui->display_window->my_data.line_width = 1;

  init_backgroud_color(ui->display_window->my_data.background_color);
  init_point_color(ui->display_window->my_data.point_color);
  init_line_color(ui->display_window->my_data.line_color);

  ui->display_window->my_data.point_size = 1;
  ui->display_window->my_data.point_type = NONE;

  set_model_transformations_to_zero();
}

void MainWindow::on_pushButton_default_settings_clicked() {
  set_parameters_to_default();
  ui->display_window->update();
  write_to_ui();
}

void MainWindow::on_xDial_sliderMoved(int position) {
  ui->lineEdit_rotation_x->setValue(position);
}

void MainWindow::on_yDial_sliderMoved(int position) {
  ui->lineEdit_rotation_y->setValue(position);
}

void MainWindow::on_zDial_sliderMoved(int position) {
  ui->lineEdit_rotation_z->setValue(position);
}

void MainWindow::on_lineEdit_rotation_x_valueChanged(int value) {
  double wAngl = static_cast<double>(value) -
                 ui->display_window->my_data.rotation_display[0];
  figure_rotation(ui->display_window->shape, wAngl, 0, 0);
  ui->display_window->my_data.rotation_display[0] = static_cast<double>(value);
  ui->display_window->update();

  ui->xDial->setValue(value);
}

void MainWindow::on_lineEdit_rotation_y_valueChanged(int value) {
  double wAngl = static_cast<double>(value) -
                 ui->display_window->my_data.rotation_display[1];
  figure_rotation(ui->display_window->shape, 0, wAngl, 0);
  ui->display_window->my_data.rotation_display[1] = static_cast<double>(value);
  ui->display_window->update();

  ui->yDial->setValue(value);
}

void MainWindow::on_lineEdit_rotation_z_valueChanged(int value) {
  double wAngl = static_cast<double>(value) -
                 ui->display_window->my_data.rotation_display[2];
  figure_rotation(ui->display_window->shape, 0, 0, wAngl);
  ui->display_window->my_data.rotation_display[2] = static_cast<double>(value);
  ui->display_window->update();

  ui->zDial->setValue(value);
}

void MainWindow::on_lineEdit_translation_x_valueChanged(int arg1) {
  ui->display_window->my_data.translation[0] = static_cast<double>(arg1);

  ui->display_window->shape->absolute_translation[0] =
      ui->display_window->my_data.translation[0] / 10;

  ui->display_window->update();
}

void MainWindow::on_lineEdit_translation_y_valueChanged(int arg1) {
  ui->display_window->my_data.translation[1] = static_cast<double>(arg1);

  ui->display_window->shape->absolute_translation[1] =
      ui->display_window->my_data.translation[1] / 10;

  ui->display_window->update();
}

void MainWindow::on_lineEdit_translation_z_valueChanged(int arg1) {
  ui->display_window->my_data.translation[2] = static_cast<double>(arg1);

  ui->display_window->shape->absolute_translation[2] =
      ui->display_window->my_data.translation[2] / 10;

  ui->display_window->update();
}

void MainWindow::on_lineEdit_scale_x_valueChanged(double arg1) {
  ui->display_window->my_data.scale[0] = arg1;
  ui->display_window->update();
}

void MainWindow::on_pushButton_make_gif_clicked() {
  std::thread gif_thread(&Display_window::saveGIF, ui->display_window);
  gif_thread.detach();
}

void MainWindow::on_pushButton_save_image_clicked() {
  QString saveDirectory = "./misc/img/";
  QString fileType = ui->fileType->currentText();

  QDir dir(saveDirectory);
  if (!dir.exists()) {
    dir.mkpath(".");
  }

  QString fileName = saveDirectory + "/";
  QTime date = QTime::currentTime();
  fileName.append(date.toString("hh_mm_ss_"));
  fileName.append(ui->display_window->my_data.name_of_model.c_str());
  fileName.append(fileType);

  QImage img = ui->display_window->grabFramebuffer();
  img.save(fileName);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
    on_pushButton_apply_changes_clicked();
  }
}

void MainWindow::closeEvent(QCloseEvent* event) {
  writeSettings();
  event->accept();
}

MainWindow::~MainWindow() { delete ui; }
