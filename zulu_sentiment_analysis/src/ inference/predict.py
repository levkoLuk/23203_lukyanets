from transformers import pipeline
from configs.model_config import load_model_config

class ZuluSentimentAnalyzer:
    def __init__(self):
        config = load_model_config()
        self.classifier = pipeline(
            "text-classification",
            model=config['training']['output_dir'],
            tokenizer=config['training']['output_dir']
        )
        self.labels = {v: k for k, v in config['label_mapping'].items()}
    
    def predict(self, text):
        result = self.classifier(text)[0]
        return {
            "text": text,
            "sentiment": self.labels[int(result['label'].split('_')[-1])],
            "confidence": result['score']
        }

if __name__ == "__main__":
    analyzer = ZuluSentimentAnalyzer()
    print(analyzer.predict("Ngiyajabula!"))