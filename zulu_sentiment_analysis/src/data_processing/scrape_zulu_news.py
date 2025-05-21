import requests
from bs4 import BeautifulSoup
import pandas as pd
from textblob import TextBlob
from configs.data_config import load_data_config

def scrape_news():
    config = load_data_config()
    urls = ["https://isolezwe.co.za/"]
    data = []
    
    for url in urls:
        try:
            response = requests.get(url)
            soup = BeautifulSoup(response.text, 'html.parser')
            
            for article in soup.find_all('article')[:10]:
                text = article.get_text(strip=True)
                sentiment = TextBlob(text).sentiment.polarity
                label = "neutral"
                if sentiment > 0.1: label = "positive"
                elif sentiment < -0.1: label = "negative"
                
                data.append({
                    "text": text,
                    "label": config['label_mapping'][label],
                    "source": url
                })
                
        except Exception as e:
            print(f"Error scraping {url}: {e}")
    
    pd.DataFrame(data).to_csv(config['data_paths']['raw']['news'], index=False)

if __name__ == "__main__":
    scrape_news()