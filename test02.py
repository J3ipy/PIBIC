import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

# Carregar os dados do CSV
data = pd.read_csv('logger.csv')

# Separar as características e o alvo
X = data[['tempo', 'valor_sensor']].values
# Supondo que você tenha uma coluna 'fome' que indica se o peixe está com fome (1) ou não (0)
# Caso contrário, precisaremos de um critério para definir isso
y = data['fome'].values

# Dividir os dados em conjuntos de treinamento e teste
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Normalizar os dados
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# Construir o modelo
model = Sequential()
model.add(Dense(32, input_dim=X_train.shape[1], activation='relu'))
model.add(Dense(16, activation='relu'))
model.add(Dense(1, activation='sigmoid'))

# Compilar o modelo
model.compile(loss='binary_crossentropy', optimizer='adam', metrics=['accuracy'])

# Treinar o modelo
model.fit(X_train, y_train, epochs=50, batch_size=10, validation_split=0.2)

# Avaliar o modelo
loss, accuracy = model.evaluate(X_test, y_test)
print(f'Acurácia: {accuracy*100:.2f}%')

# Fazer previsões
predictions = model.predict(X_test)
predictions = (predictions > 0.5).astype(int)

# Mostrar algumas previsões
for i in range(5):
    print(f'Entrada: {X_test[i]}, Previsão: {"Fome" if predictions[i] == 1 else "Sem Fome"}, Real: {"Fome" if y_test[i] == 1 else "Sem Fome"}')
