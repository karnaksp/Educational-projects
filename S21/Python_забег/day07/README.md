## Документация со sphinx

Запускаем утилиту для генерации конфигурационных файлов
```
cd Ex02
sphinx-quickstart
```

Редактируем source/config.py

```python
import os
import sys

sys.path.insert(0, os.path.abspath("../../Ex00")) # включает относительные пути для подключения нужных модулей
sys.path.insert(0, os.path.abspath("../../Ex01"))
```

Запускаем дополнительную утилиту для автоматической генерации `.rst` файлов

```
cd Ex02/ && sphinx-apidoc -o source ../Ex00
cd Ex02/ && sphinx-apidoc -o source ../Ex01
```

Вписываем эти модули в основной файл `index.rst`:

```
.. toctree::
   :maxdepth: 2
   :caption: Modules:

   ex00
   ex01
```

Далее можно запускать `make html` для генерации документации со всеми подключенными модулями.


```
src
├─ Ex00
│  ├─ check_input.py
│  ├─ main.py
│  ├─ questions.json
│  ├─ simulate_user.py
│  └─ voit_kampf_test.py
├─ Ex01
│  ├─ run_test.sh
│  ├─ test_input.py
│  └─ test_vktester.py
├─ Ex02
│  ├─ build
│  └─ source
│     ├─ _static
│     │  └─ logo.png
│     ├─ _templates
│     ├─ conf.py
│     └─ index.rst
├─ Dockerfile
├─ Makefile
├─ cat.sh
├─ requirements.txt
└─ venv

```