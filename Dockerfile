FROM alpine:3.10

RUN apk add --no-cache python3-dev \
    && pip3 install --upgrade pip

RUN pip install flask-bootstrap

RUN set -e; \
        apk add --no-cache --virtual .build-deps \
                gcc \
                libc-dev \
                linux-headers \
                mariadb-dev \
                python3-dev \
                postgresql-dev \
        ;
RUN pip install flask-mysqldb 

WORKDIR /app
COPY . /app

RUN pip3 --no-cache-dir install -r requirements.txt


CMD ["python3", "src/app.py"]
