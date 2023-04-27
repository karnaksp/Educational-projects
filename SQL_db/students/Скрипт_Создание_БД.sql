-- -----------------------------------------------------
-- Table KURSOVAYA_UGL.ref_faculty
-- -----------------------------------------------------
CREATE TABLE ref_faculty (
  id INT NOT NULL IDENTITY(1,1),
  name VARCHAR(255) NOT NULL,
  PRIMARY KEY (id)
);

CREATE UNIQUE INDEX id_ref_faculty_UNIQUE ON ref_faculty(id);
CREATE UNIQUE INDEX name_ref_faculty_UNIQUE ON ref_faculty(name);

-- -----------------------------------------------------
-- Table KURSOVAYA_UGL.ref_degree
-- -----------------------------------------------------
CREATE TABLE ref_degree (
  id INT NOT NULL IDENTITY(1,1),
  name VARCHAR(50) NOT NULL,
  PRIMARY KEY (id)
);

CREATE UNIQUE INDEX id_ref_degree_UNIQUE ON ref_degree(id);
CREATE UNIQUE INDEX name_ref_degree_UNIQUE ON ref_degree(name);

-- -----------------------------------------------------
-- Table KURSOVAYA_UGL.ref_group
-- -----------------------------------------------------
CREATE TABLE ref_group (
  group_id INT NOT NULL IDENTITY(1,1),
  group_num VARCHAR(100) NOT NULL,
  course INT NOT NULL,
  faculty_id INT NOT NULL,
  degree_id INT NOT NULL,
  PRIMARY KEY (group_id),
  CONSTRAINT check_course
    CHECK (course BETWEEN 0 AND 10),
  CONSTRAINT fk_ref_group_ref_raculty
    FOREIGN KEY (faculty_id)
    REFERENCES ref_faculty(id)
    ON UPDATE CASCADE,
  CONSTRAINT fk_ref_group_ref_degree
    FOREIGN KEY (degree_id)
    REFERENCES ref_degree(id)
    ON UPDATE CASCADE
);

CREATE INDEX fk_ref_group_ref_faculty ON ref_group(faculty_id);
CREATE INDEX fk_ref_group_ref_degree ON ref_group(degree_id);
CREATE UNIQUE INDEX group_id_ref_group_UNIQUE ON ref_group(group_id);

-- -----------------------------------------------------
-- Table KURSOVAYA_UGL.student
-- -----------------------------------------------------
CREATE TABLE student (
  id INT NOT NULL IDENTITY(1,1),
  name VARCHAR(150) NOT NULL,
  surname VARCHAR(150) NOT NULL,
  lastname VARCHAR(150) NOT NULL,
  birthday DATE NOT NULL,
  phone VARCHAR(45) NULL,
  email VARCHAR(100) NULL,
  is_monitor BIT NOT NULL,
  PRIMARY KEY (id)
);

CREATE UNIQUE INDEX id_student_UNIQUE ON student(id);

-- -----------------------------------------------------
-- Table KURSOVAYA_UGL.ref_subject
-- -----------------------------------------------------
CREATE TABLE ref_subject (
  id INT NOT NULL IDENTITY(1,1),
  name VARCHAR(255) NOT NULL,
  PRIMARY KEY (id)
);

CREATE UNIQUE INDEX name_ref_subject_UNIQUE ON ref_subject(name);
CREATE UNIQUE INDEX id_ref_subject_UNIQUE ON ref_subject(id);

-- -----------------------------------------------------
-- Table KURSOVAYA_UGL.ref_department
-- -----------------------------------------------------
CREATE TABLE ref_department (
  id INT NOT NULL IDENTITY(1,1),
  name VARCHAR(255) NOT NULL,
  PRIMARY KEY (id)
);

CREATE UNIQUE INDEX id_ref_department_UNIQUE ON ref_department(id);
CREATE UNIQUE INDEX name_ref_department_UNIQUE ON ref_department(name);

-- -----------------------------------------------------
-- Table KURSOVAYA_UGL.employee
-- -----------------------------------------------------
CREATE TABLE employee (
  id INT NOT NULL IDENTITY(1,1),
  surname VARCHAR(150) NOT NULL,
  name VARCHAR(150) NOT NULL,
  lastname VARCHAR(150) NOT NULL,
  stazh INT NOT NULL,
  birthday DATE NOT NULL,
  phone VARCHAR(45) NOT NULL,
  email VARCHAR(150) NOT NULL,
  ref_department_id INT NOT NULL,
  PRIMARY KEY (id),
  CONSTRAINT fk_employee_ref_department1
    FOREIGN KEY (ref_department_id)
    REFERENCES ref_department (id)
    ON UPDATE CASCADE
);

CREATE UNIQUE INDEX email_employee_UNIQUE ON employee(email);
CREATE UNIQUE INDEX phone_Uemployee_NIQUE ON employee(phone);
CREATE UNIQUE INDEX id_employee_UNIQUE ON employee(id);
CREATE INDEX fk_employee_ref_department1_idx ON employee(ref_department_id);

-- -----------------------------------------------------
-- Table KURSOVAYA_UGL.mark_rating_sheet
-- -----------------------------------------------------
CREATE TABLE mark_rating_sheet (
  id INT NOT NULL IDENTITY(1,1),
  employee_id INT NOT NULL,
  subject_id INT NOT NULL,
  group_id INT NOT NULL,
  is_lecturer BIT NOT NULL,
  is_tutor BIT NOT NULL,
  working_hours INT NOT NULL,
  duration INT NOT NULL,
  PRIMARY KEY (id),
  CONSTRAINT fk_mark_rating_sheet_employee
    FOREIGN KEY (employee_id)
    REFERENCES employee (id)
    ON UPDATE CASCADE,
  CONSTRAINT fk_mark_rating_sheet_ref_subject
    FOREIGN KEY (subject_id)
    REFERENCES ref_subject (id)
    ON UPDATE CASCADE,
  CONSTRAINT fk_mark_rating_sheet_ref_group
    FOREIGN KEY (group_id)
    REFERENCES ref_group (group_id)
    ON UPDATE CASCADE
);

CREATE INDEX fk_mark_rating_sheet_ref_subject ON mark_rating_sheet(subject_id);
CREATE INDEX fk_mark_rating_sheet_ref_group ON mark_rating_sheet(group_id);
CREATE UNIQUE INDEX brv ON mark_rating_sheet(employee_id, subject_id, group_id);
CREATE INDEX fk_mark_rating_sheet_employee ON mark_rating_sheet(employee_id);

-- -----------------------------------------------------
-- Table KURSOVAYA_UGL.student_group
-- -----------------------------------------------------
CREATE TABLE student_group (
  student_id INT NOT NULL,
  group_id INT NOT NULL,
  PRIMARY KEY (student_id, group_id),
  CONSTRAINT fk_student_group_student
    FOREIGN KEY (student_id)
    REFERENCES student (id)
    ON UPDATE CASCADE,
  CONSTRAINT fk_student_group_group
    FOREIGN KEY (group_id)
    REFERENCES ref_group (group_id)
    ON UPDATE CASCADE
);

CREATE INDEX fk_student_group_group_idx ON student_group(group_id);
CREATE INDEX fk_student_group_student_idx ON student_group(student_id);

-- -----------------------------------------------------
-- Table KURSOVAYA_UGL.daily_mark_rating_record
-- -----------------------------------------------------
CREATE TABLE daily_mark_rating_record (
  mark_rating_sheet_id INT NOT NULL,
  student_id INT NOT NULL,
  date DATE NOT NULL,
  attendance BIT NOT NULL,
  activity DECIMAL(4,2) NOT NULL,
  tests DECIMAL(4,2) NOT NULL,
  exam DECIMAL(4,2) NOT NULL,
  PRIMARY KEY (mark_rating_sheet_id, student_id, date),
  CONSTRAINT fk_daily_mark_rating_record_mark_rating_sheet
    FOREIGN KEY (mark_rating_sheet_id)
    REFERENCES mark_rating_sheet (id)
    ON UPDATE CASCADE,
  CONSTRAINT fk_daily_mark_rating_record_student
    FOREIGN KEY (student_id)
    REFERENCES student (id)
    ON UPDATE CASCADE
);

CREATE INDEX fk_daily_mark_rating_record_student1_idx ON daily_mark_rating_record(student_id);
CREATE INDEX fk_daily_mark_rating_record_sheet ON daily_mark_rating_record(mark_rating_sheet_id);