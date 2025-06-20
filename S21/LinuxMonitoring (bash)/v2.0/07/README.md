
## Получить доступ к веб интерфейсам **Prometheus** и **Grafana** с локальной машины

* Чтобы перейти в панель `Grafana` используем браузер перейдем по адресу нашего сервера с установленной Graphana и порт (обычно 3000)
`http://172.20.10.8:3000`
* При первом запуске вводим логин: `admin` и пароль: `admin`. После этого будет предложено заменить пароль<br/>
* После этого перейдем `Configuration->Data Source` и нажимаем кнопку `Add Data Source`<br/>
* В открывшемся окне выбираем тип Data Source - `Prometheus`<br/>
* В поле URL вводим адрес сервера, на котором доступен `Prometheus` и его порт. Так как `Grafana` находится на той же машине, что и `Prometheus` (порт по умолчанию 9090), используем `http://172.20.10.8:9090` <br/>
* Сохраняем изменения `Save and Test`<br/>

## Добавить на дашборд **Grafana** отображение ЦПУ, доступной оперативной памяти, свободное место и кол-во операций ввода/вывода на жестком диске. Запустить ваш bash-скрипт из [Части 2]. Посмотреть на нагрузку жесткого диска (место на диске и операции чтения/записи)

Для создание dashboard нажимаем `Add panel->Add new panel`<br/>

Создаем по очереди панели для отображения:
1. `CPU`<br/>
2. `доступной оперативной памяти`<br/>
3. `всей памяти`, `занятой памяти` и `свободной памяти`<br/>
4. `количества операций ввода/вывода на жестком диске`<br/>

Запустим bash-скрипт из `Part 2` и смотрим на нагрузку жесткого диска
![part_7](./images/1.png)

## Установить утилиту **stress** и запустить команду `stress -c 2 -i 1 -m 1 --vm-bytes 32M -t 10s` Посмотреть на нагрузку жесткого диска, оперативной памяти и ЦПУ
Установим утилиту `stress`
    ```
     sudo apt install stress
    ```
* Запустим команду
    ```
     stress -c 2 -i 1 -m 1 --vm-bytes 32M -t 60s
    ```
* Проверим результаты работы
    ![part_7](./images/2.png)<br/>