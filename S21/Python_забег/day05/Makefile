REQUIREMENTS_FILE = ./requirements.txt

.PHONY: all clean Ex00 Ex01 Ex02 start_server_flask start_server stop_server start_client_flask

all: cat

start_server_flask:
	@./cat.sh "Starting server on port 8888..." 10
	@cd Ex01 && \
	python3 -m venv venv && \
	bash -c "source venv/bin/activate && \
	pip install -r $(REQUIREMENTS_FILE) && \
	cd server && \
	sudo chmod -R 777 static/uploads && \
	python app.py"

start_client_flask:
	@./cat.sh "Starting client..." 10
	@bash -c "source Ex01/venv/bin/activate && \
	cd Ex01/client && \
	python screwdriver.py upload ../../descent_-_Memories.mp3 && \
	python screwdriver.py list"

start_server:
	@./cat.sh "Starting WSGI server on port 8888..." 10
	@cd $${DIR} && python credentials.py & echo $$! > server.pid

stop_server:
	@./cat.sh "Stopping WSGI server..." 10
	@if [ -f server.pid ]; then \
		kill `cat server.pid` && rm server.pid; \
	else \
		echo "No server.pid file found. Nothing to stop."; \
	fi

Ex00:
	@DIR="Ex00" $(MAKE) --no-print-directory start_server
	@sleep 2
	@curl http://127.0.0.1:8888/?species=Time%20Lord

Ex01: start_server_flask
	# start_client_flask

Ex02:
	@./cat.sh "Running Ex02..." 10
	@python Ex02/doctors.py 

cat:
	@chmod +x cat.sh
