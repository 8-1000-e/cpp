import os

def create_cpp_for_hpp(root_dir='.'):
    for dirpath, _, filenames in os.walk(root_dir):
        for filename in filenames:
            if filename.endswith('.hpp'):
                hpp_path = os.path.join(dirpath, filename)
                cpp_filename = filename[:-4] + '.cpp'  # remplace .hpp par .cpp
                cpp_path = os.path.join(dirpath, cpp_filename)
                
                if not os.path.exists(cpp_path):
                    print(f"Création de : {cpp_path}")
                    with open(cpp_path, 'w') as f:
                        pass  # crée un fichier vide
                else:
                    print(f"Le fichier {cpp_path} existe déjà, il n'a pas été écrasé.")

if __name__ == "__main__":
    create_cpp_for_hpp()
