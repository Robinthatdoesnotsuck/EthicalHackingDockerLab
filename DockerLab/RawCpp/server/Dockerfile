FROM python:3.10-rc-buster


ENV FLASK_APP server.py
ENV FLASK_RUN_HOST 0.0.0.0

COPY requirements.txt requirements.txt

RUN pip install -r requirements.txt

COPY . .
WORKDIR /code
CMD ["flask", "run"]
