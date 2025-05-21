import pandas as pd
from googletrans import Translator
from configs.data_config import load_data_config

def generate_synthetic_data():
    config = load_data_config()
    translator = Translator()
    
    english_examples = [
        ("I love this", "positive"),
        ("This is terrible", "negative"),
        ("It's okay", "neutral")
    ]
    
    data = []
    for text, label in english_examples:
        try:
            translation = translator.translate(text, src='en', dest='zu').text
            data.append({
                "text": translation,
                "label": config['label_mapping'][label],
                "source": "synthetic"
            })
        except:
            continue
    
    pd.DataFrame(data).to_csv(config['data_paths']['raw']['manual'], index=False)

if __name__ == "__main__":
    generate_synthetic_data()