
from flask import Flask, request, jsonify
import mysql.connector

app = Flask(__name__)

# 🔗 connect to MySQL
db = mysql.connector.connect(
    host="localhost",
    user="root",
    password="Bu@#1234",   # 👈 put your MySQL password
    database="login_systems"
)

cursor = db.cursor()
@app.route('/')
def home():
    return "Flask + MySQL connected successfully!"


@app.route('/signup', methods=['POST'])
def signup():
    data = request.json

    username = data['username']
    email = data['email']
    password = data['password']

    try:
        cursor.execute(
            "INSERT INTO users (username, email, password) VALUES (%s, %s, %s)",
            (username, email, password)
        )
        db.commit()

        return jsonify({"message": "User created successfully!"})

    except:
        return jsonify({"message": "Username or email already exists!"})
    

    # for login
    
@app.route('/login', methods=['POST'])
def login():
    data = request.json

    username = data['username']
    password = data['password']

    cursor.execute(
        "SELECT * FROM users WHERE username=%s AND password=%s",
        (username, password)
    )

    user = cursor.fetchone()

    if user:
        return jsonify({"message": "Login successful!"})
    else:
        return jsonify({"message": "Invalid username or password"})
# 🔥 ALWAYS KEEP THIS LAST
if __name__ == '__main__':
    app.run(debug=True)
