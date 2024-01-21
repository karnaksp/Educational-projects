# 3DViewer v1.0

В этом проекте реализована программа для просмотра каркасных 3D-моделей (`./s21_3Dviewer_v1`): функционал написан на языке программирования C (полностью покрыт unit-тестами <check.h>), а фронт на C++ с использованием фреймворка QT. Сами модели загружаются из файлов .obj и доступны для просмотра на экране с возможностью вращения, масштабирования и перевода.

**Для компиляции в Docker**, находясь в папке C8_3DViewer_v1.0-1/ , запустите команды: 

```bash
docker buildx create --use
<some_image> -- Вывод с именем вашего контейнера
docker buildx build -t localhost:5000/<some_image>:tag . --load
docker push localhost:5000/<some_image>:tag
```
И затем скопируем исполняемый файл в текущую директорию.
```bash
docker pull localhost:5000/<some_image>:tag
docker run -v ./:/output -it localhost:5000/<some_image>:tag
```

Для запуска программы, ввести в терминале

```bash
./s21_3Dviewer_v1 
```
___________

**Для компиляции в вашей системе linux**, необходимо скачать все зависимости, описанные в [manual.texi файле](./src/manual.texi) и выполнить:

```bash
make
```

И для запуска 
```bash
make run
```

![gif](src/gif/3DViewer.gif)