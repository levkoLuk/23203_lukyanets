import pandas as pd
from sklearn.model_selection import train_test_split
from configs.data_config import load_data_config

def clean_and_split():
    config = load_data_config()
    
    news = pd.read_csv(config['data_paths']['raw']['news'])
    manual = pd.read_csv(config['data_paths']['raw']['manual'])
    combined = pd.concat([news, manual]).drop_duplicates()
    
    combined = combined.dropna()
    combined.to_csv(config['data_paths']['processed']['cleaned'], index=False)
    
    train, test = train_test_split(combined, test_size=0.2)
    train.to_csv(config['data_paths']['processed']['train'], index=False)
    test.to_csv(config['data_paths']['processed']['test'], index=False)
    
    combined.to_csv(config['data_paths']['final'], index=False)

if __name__ == "__main__":
    clean_and_split()
