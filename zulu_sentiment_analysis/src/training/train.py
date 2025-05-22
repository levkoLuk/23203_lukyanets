from transformers import (
    BertForSequenceClassification,
    BertTokenizer,
    Trainer,
    TrainingArguments
)
from datasets import load_dataset
import yaml
import torch
from torch.utils.data import Dataset

class ZuluDataset(Dataset):
    def __init__(self, encodings, labels):
        self.encodings = encodings
        self.labels = labels
    
    def __getitem__(self, idx):
        item = {key: torch.tensor(val[idx]) for key, val in self.encodings.items()}
        item['labels'] = torch.tensor(self.labels[idx])
        return item
    
    def __len__(self):
        return len(self.labels)

def train():
    with open("configs/model_config.yaml") as f:
        config = yaml.safe_load(f)
    dataset = load_dataset('csv', data_files='data/processed/train_dataset.csv')
    tokenizer = BertTokenizer.from_pretrained(config['model']['name'])
    
    encodings = tokenizer(
        dataset['train']['text'],
        truncation=True,
        padding=True,
        max_length=config['model']['params']['max_length']
    )
    
    train_dataset = ZuluDataset(encodings, dataset['train']['label'])
    
    model = BertForSequenceClassification.from_pretrained(
        config['model']['name'],
        num_labels=config['model']['params']['num_labels']
    )
    
    training_args = TrainingArguments(
        output_dir=config['training']['output_dir'],
        num_train_epochs=config['training']['epochs'],
        per_device_train_batch_size=config['training']['batch_size'],
        learning_rate=config['training']['learning_rate']
    )
    
    trainer = Trainer(
        model=model,
        args=training_args,
        train_dataset=train_dataset
    )
    
    trainer.train()
    trainer.save_model()

if __name__ == "__main__":
    train()
