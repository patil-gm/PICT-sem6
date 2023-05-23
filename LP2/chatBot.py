import random

# Predefined responses for the chatbot
greetings = ["Hello!", "Hi there!", "Welcome!"]
farewells = ["Thank you for contacting us. Take care!", "Have a great day!", "Goodbye! Take care."]

# Function to generate a random greeting
def get_greeting():
    return random.choice(greetings)

# Function to generate a random farewell
def get_farewell():
    return random.choice(farewells)

doctors = [
    {"name": "Dr. John Smith", "specialty": "Cardiology", "day": ["Monday", "Wednesday", "Friday"]},
    {"name": "Dr. Sarah Johnson", "specialty": "Dermatology", "day": ["Tuesday", "Thursday"]},
    {"name": "Dr. Michael Brown", "specialty": "Orthopedics", "day": ["Monday", "Wednesday"]},
    {"name": "Dr. Emily Davis", "specialty": "Pediatrics", "day": ["Tuesday", "Thursday", "Friday"]},
    {"name": "Dr. Robert Wilson", "specialty": "Ophthalmology", "day": ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday"]}
]

def search(spec,day):
    for x in doctors:
        if x["specialty"]==spec and day in x["day"]:
            return x
    
lst=[]
# Function to handle user inquiries
def process_input(user_input):
    if "help" in user_input.lower():
        return "how can i help you?"
    elif "doctors" in user_input.lower() or "specialists" in user_input.lower():
        print( "We have a wide range of doctors and specialists. Please let me know the type of doctor you are looking for.")
        spec=input("enter which type of dr:")
        day=input("in which day:")
        return search(spec,day)

    elif "appointment" in user_input.lower() or "schedule" in user_input.lower():
        print( "To schedule an appointment, please provide your name")
        
        lst.append()
    elif "emergency" in user_input.lower():
        return "In case of an emergency, please call 911 immediately."
    elif "thank you" in user_input.lower() or "thanks" in user_input.lower():
        return "You're welcome! If you have any more questions, feel free to ask."
    else:
        return "I'm sorry, but I couldn't understand your inquiry. Can you please rephrase or provide more details?"

# Main conversation loop
print(get_greeting())

while True:
    user_input = input("User: ")
    response = process_input(user_input)
    print("ChatBot:", response)
    
    # Check for exit condition
    if "bye" in user_input.lower() or "goodbye" in user_input.lower() or "exit" in user_input.lower():
        print(get_farewell())
        break
