Для запуска тестирвоания работы этого задания:

Устанавливаем redis:

```bash
sudo apt-get install redis-server
```

В одном терминале запускаем redis:

```bash
redis-cli
```

В другом терминале запускаем сервер

```bash
make Ex02
```

На другом/их терминале/ах от клиента передаем список url:

```bash
make run_client
```
Далее првоеряем, что все кешировалось либо повторным запросом, либо через терминал с `redis-cli`:

```bash
localhost:6379> GET cache:http://example.com
```
