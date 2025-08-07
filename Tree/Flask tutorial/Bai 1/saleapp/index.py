from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def home():
    #return "Hello World!!!"
    return render_template("index.html")

@app.route("/test")
def test():
    return "Welcome to my web!!!"
if __name__ == "__main__":
    app.run(debug = True)