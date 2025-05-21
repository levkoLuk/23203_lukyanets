import yaml
import os

def load_config(file_path):
    with open(file_path) as f:
        return yaml.safe_load(f)

def ensure_dir_exists(path):
    os.makedirs(path, exist_ok=True)