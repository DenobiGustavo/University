from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/webhook', methods=['POST'])
def webhook():
    data = request.json
    print('Recebi um webhook:', data)
    return jsonify({'message': 'Webhook recebido com sucesso!'}), 200

if __name__ == '__main__':
    app.run(port=5000)
