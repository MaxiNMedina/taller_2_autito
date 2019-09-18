from flask import Flask, render_template
from flask import request
from flask_bootstrap import Bootstrap
import requests

app = Flask(__name__)
Bootstrap(app)

@app.route('/', methods= ['GET', 'POST'])
def index():
    return render_template('index.html') 

@app.route('/adelante')
def adelante():
    return requests.get('http://192.168.4.1/1')

@app.route('/atras')
def atras():
    return requests.get('http://192.168.4.1/2')

@app.route('/izquierda')
def izquierda():
    return requests.get('http://192.168.4.1/3')

@app.route('/derecha')
def derecha():
    return requests.get('http://192.168.4.1/4')

@app.route('/parar')
def parar():
    return requests.get('http://192.168.4.1/5')

@app.route('/velocidad')
def action_form(vel=None):
	nom = requests.args["http://192.168.4.1/6"]
	return render_template('velocidad.html', velocidad=vel)

if __name__ == "__main__":
	app.run(host='0.0.0.0', port=4000, debug=True)