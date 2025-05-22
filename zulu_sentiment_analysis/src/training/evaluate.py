from transformers import pipeline
from sklearn.metrics import classification_report
import pandas as pd

def evaluate():
    classifier = pipeline(
        "text-classification",
        model="models/trained_model",
        tokenizer="models/trained_model"
    )
    
    test_data = pd.read_csv("data/processed/test_dataset.csv")
    
    predictions = classifier(list(test_data['text']))
    predicted_labels = [int(p['label'].split('_')[-1]) for p in predictions]
    
    print(classification_report(
        test_data['label'],
        predicted_labels,
        target_names=['positive', 'negative', 'neutral']
    ))

if __name__ == "__main__":
    evaluate()
