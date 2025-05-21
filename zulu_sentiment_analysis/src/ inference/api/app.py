from fastapi import FastAPI
from .predict import ZuluSentimentAnalyzer

app = FastAPI()
analyzer = ZuluSentimentAnalyzer()

@app.post("/analyze")
async def analyze(text: str):
    return analyzer.predict(text)

@app.get("/")
async def health_check():
    return {"status": "healthy"}