## PART 1. Ansible

Настроили ssh подключение между manager и nodes:

![](screenshots/Pasted%20image%2020250203140438.png)


настроили машину manager, сгенерировали ssh ключи и положили их в общую папку, установили ansible:

![](screenshots/Pasted%20image%2020250203135926.png)


настроили машины nodes,  скопировали ключ в authorized_keys, установили python3 для работы ansible:

![](screenshots/Pasted%20image%2020250203140040.png)

inventory file:

![](screenshots/Pasted%20image%2020250203135808.png)

ansible ping:

![](screenshots/Pasted%20image%2020250203135734.png)

написали playbook 

![](screenshots/Pasted%20image%2020250203202511.png)


запустили

![](screenshots/Pasted%20image%2020250203202132.png)


работает

![](screenshots/Pasted%20image%2020250203202153.png)

внатуре работает

![](screenshots/Pasted%20image%2020250203202118.png)

## Разбиение на роли

![](screenshots/Pasted%20image%2020250206185546.png)

создали 3 папки в roles в каждой из которых в папке tasks в файле main.yml указали таски

создали в домашней директории .ansible.cfg

![](screenshots/Pasted%20image%2020250206185800.png)


микросервисное приложение работает

![](screenshots/Pasted%20image%2020250206192336.png)

postgres работает

![](screenshots/Pasted%20image%2020250206184618.png)


apache работает


![](screenshots/Pasted%20image%2020250206185835.png)

## Part2. Consul

Итак нам необходимо построить такую архитектуру service mesh, где сервисы не напрямую общаются друг с другом, а через прокси, которое конфигурируется control plane или в нашем случае consul_server.

![](screenshots/Pasted%20image%2020250212130706.png)


Порядок действий
- создадим машины vagrant-ом
- сконфигуряем машины ansibl-ом
- создадим systemd services для запуска и работы всего в фоне
- долно работать


создаём 4 машины вагнатом 

![](screenshots/Pasted%20image%2020250212131309.png)

consul_client.hcl

![](screenshots/Pasted%20image%2020250212130959.png)

consul_server.hcl

![](screenshots/Pasted%20image%2020250212131011.png)


затем конфиг файлы .json для envoy proxy

![](screenshots/Pasted%20image%2020250212131046.png)

![](screenshots/Pasted%20image%2020250212131054.png)

и systemd unit-ы для работы

![](screenshots/Pasted%20image%2020250212131121.png)

![](screenshots/Pasted%20image%2020250212131149.png)


конфигуряем ansible для автораскатки

основной playbook

![](screenshots/Pasted%20image%2020250212131432.png)


4 роли с файлами

создаём папку roles в ней 4 папки с ролями, в каждой из которых такой порядок:
- files - файлы для пересылки на сервер
- tasks - ansible таски
- templates - то же, что и files, только ansible туда подставляет значения
- vars - здесь хранятся переменные

пример одной из ролей а именно install_hotels_service

![](screenshots/Pasted%20image%2020250212131729.png)


![](screenshots/Pasted%20image%2020250212131742.png)

пример шаблона systemd unit-a

![](screenshots/Pasted%20image%2020250212131904.png)




приложение работает!!! УРААААА! стучусь к нему с локальной машины своей

![](screenshots/Pasted%20image%2020250211211403.png)

![](screenshots/Pasted%20image%2020250211212822.png)

![](screenshots/Pasted%20image%2020250211212900.png)

![](screenshots/Pasted%20image%2020250211212930.png)


подняли остальное приложение в докере на локальной машине и прогнали тесты, которые взаимодействуют с нашим hotel-service и бд


![](screenshots/Pasted%20image%2020250212162948.png)