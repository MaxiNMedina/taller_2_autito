from flask import Flask, render_template
from flask import request
from flask_bootstrap import Bootstrap
import requests
from flask_mysqldb import MySQL

app = Flask(__name__)
Bootstrap(app)

'''app.config['MYSQL_HOST'] = 'localhost'
app.config['MYSQL_USER'] = 'maximedina'
app.config['MYSQL_PASSWORD'] = 'maximedina'
app.config['MYSQL_DB'] = 'autito'
mysql = MySQL(app)'''

@app.route('/', methods= ['GET', 'POST'])
def index():
    '''cur = mysql.connection.cursor()
    cur.execute('SELECT * FROM usuarios')
    data = cur.fetchall()
    print(data)'''
    return render_template('index.html') 

@app.route('/adelante')
def adelante():
    requests.get('http://192.168.4.1/1')
    return render_template('index.html') 

@app.route('/atras')
def atras():
   requests.get('http://192.168.4.1/2')
   return render_template('index.html') 

@app.route('/izquierda')
def izquierda():
    requests.get('http://192.168.4.1/3')
    return render_template('index.html') 

@app.route('/derecha')
def derecha():
    requests.get('http://192.168.4.1/4')
    return render_template('index.html') 

@app.route('/parar')
def parar():
    requests.get('http://192.168.4.1/5')
    return render_template('index.html') 

@app.route('/velocidad')
def action_form(vel=None):
	nom = requests.args["http://192.168.4.1/6"]
	return render_template('velocidad.html', velocidad=vel)

if __name__ == "__main__":
	app.run(host='0.0.0.0', port=4000, debug=True)