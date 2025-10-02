import random

# Function to build the Markov chain
def build_markov_chain(text, n=2):
    words = text.split()
    chain = {}
    
    for i in range(len(words) - n):   #This sequence selects words from the source_text,and splits them carefully into key and their values.
        key = tuple(words[i:i+n])
        next_word = words[i+n]
        chain.setdefault(key, []).append(next_word)
    
    return chain

# Function to generate text from the chain
def generate_text(chain, length=10):
    key = random.choice(list(chain.keys()))  # Start with a random state
    result = list(key)
    
    for _ in range(length):   #Then,create a list from a tuple and randomly add possible word combinations from our source_text.
        next_words = chain.get(key)
        if not next_words:
            break
        next_word = random.choice(next_words)
        result.append(next_word)
        key = tuple(result[-len(key):])   #Takes words from the result and turns them into a tuple.
    
    return ' '.join(result)

# Your source text
source_text = "I love pizza. I love burgers. I love coding."

# Build the chain
chain = build_markov_chain(source_text, n=2)

# Generate text
generated = generate_text(chain, length=15)
print(generated)



