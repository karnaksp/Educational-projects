# Day 03 - Python Bootcamp

> Exercise 00: Innocent Prank

`exploit.py`, который:
1. Читает файл `evilcorp.html`.
2. Меняет заголовок страницы на "Evil Corp - Stealing your money every day".
3. Парсит имя пользователя с страницы и добавляет в `body` тег `<h1>` с текстом `"<h1>Mr. Robot, you are hacked!</h1>"`.
4. Вставляет скрипт `hack_script.js` в `body`.
5. Меняет ссылку внизу страницы на `"https://mrrobot.fandom.com/wiki/Fsociety"`, заменяя имя компании на "Fsociety".

Итоговый файл сохраянется как `evilcorp_hacked.html`.

> Exercise 01: Cash Flow

 `producer.py` и `consumer.py`:
1. `producer.py` генерирует JSON-сообщения и отправляет их в очередь Redis pubsub.
2. `consumer.py` принимает список номеров аккаунтов и обрабатывает сообщения из очереди. Если номер получателя есть в списке "плохих парней" и сумма положительная, меняет местами отправителя и получателя.

> Exercise 02: Deploy

Скрипт `gen_ansible.py`, который генерирует `deploy.yml` из `todo.yml`. Задачи:
- Установка пакетов;
- Копирование файлов;
- Выполнение файлов на удаленном сервере через Python.

Используется формат Ansible.
