import re
import random

rules = {
    'greeting': {
        'patterns': [r'hello', r'hi', r'hey'],
        'responses': ['Hello! Welcome to our food ordering service.', 'Hi there! How can I assist you with your order?']
    },
    'menu': {
        'patterns': [r'menu', r'options'],
        'responses': ['Sure! Here is our menu: ...\n 1.Pav Bhaji \n 2.Vada Pav \n 3.Maggi \n 4.Chai'],
    },
    'food items' : {
        'patterns' : [r'Vada Pav',r'Pav Bhaji',r'Chai',r'Maggi' ],
        'responses' : ['Do you want to confirm your order??'],
    },
    'order': {
        'patterns': [r'order', r'I want to order'],
        'responses': ['Great! Please let me know what items you would like to order.'],
    },
    'customization': {
        'patterns': [r'customize', r'special request'],
        'responses': ['Certainly! Let me know your specific requirements or any dietary restrictions.'],
    },
    'confirm_order': {
        'patterns': [r'yes',r'confirm', r'place order'],
        'responses': ['Perfect! Your order has been placed. The estimated delivery time is approximately 30 minutes.'],
    },
    'gratitude' : {
        'patterns' : [r'thank you'],
        'responses' : ['My pleasure']
    },
    'cancel_order': {
        'patterns': [r'cancel', r'change', r'update'],
        'responses': ['I apologize for the inconvenience. Please contact our customer support for order modifications.'],
    },
    'goodbye': {
        'patterns': [r'bye', r'goodbye', r'see you'],
        'responses': ['Thank you for choosing our food ordering service.'],
    },
    'default': {
        'responses': ['Im sorry, I didnt understand that. Can you please rephrase?']
    }
}

def match_patterns(user_input,patterns):
    for pattern in patterns:
        match=re.search(user_input,pattern,re.IGNORECASE)
        if match:
            return True
    return False

def get_response(user_input):
    for intent,data in rules.items():
        patterns=data.get('patterns')
        if patterns and match_patterns(user_input,patterns):
            return random.choice(data.get('responses'))
    return random.choice(rules['default']['responses'])

def chat():
    print('Chatbot : HELLO WELCOME :)')

    while True:
        user_input=input('User : ')
        response=get_response(user_input)
        print("Chatbot : ",response)

        if any(re.search(user_input,pattern) for pattern in rules['goodbye']['patterns']):
            break

chat()
