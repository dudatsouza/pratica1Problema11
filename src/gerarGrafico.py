import pandas as pd
import plotly.graph_objects as go

# Carregar os dados do arquivo CSV
df = pd.read_csv('./datasets/tempos_execucao.csv')

# Criar o gráfico de linhas
fig = go.Figure()

# Adicionar as linhas ao gráfico com sombras correspondentes
for col in df.columns[1:]:
    fig.add_trace(go.Scatter(
        x=df['QuantidadeConjuntos'], 
        y=df[col], 
        mode='lines+markers', 
        name=col,
        marker=dict(size=10)  # Define o tamanho das bolinhas
    ))
    
# Adicionar título e nomes dos eixos
fig.update_layout(
    title={
        'text': 'DESEMPENHO DAS PROPOSTAS',
        'x': 0.5,
        'xanchor': 'center',
        'yanchor': 'top',
        'font': {'family': 'Courier New', 'size': 40, 'color': 'white'}
    },
    xaxis_title='Quantidade de Conjuntos',
    yaxis_title='Tempo de Execução',
    font=dict(
        family="sans-serif",
        size=14,
        color="#7f7f7f"
    ),
    paper_bgcolor="black",
    plot_bgcolor="black",
    legend=dict(
        x=1,
        y=1,
        traceorder='normal',
        font=dict(
            family='sans-serif',
            size=12,
            color='white'
        ),
        bgcolor='black',
        bordercolor='black',
        borderwidth=1
    ),
    xaxis=dict(
        gridcolor='rgba(255, 255, 255, 0.2)'  # Cor branca com 20% de opacidade
    ),
    yaxis=dict(
        gridcolor='rgba(255, 255, 255, 0.2)'  # Cor branca com 20% de opacidade
    )
)

fig.add_annotation(
    text="Quantidade de Conjuntos x Tempo de Execução",
    xref="paper", yref="paper",
    x=0.5, y=1.02,  # Posiciona a legenda abaixo do título
    showarrow=False,
    font=dict(
        family="Courier New",
        size=18,
        color="rgba(255, 255, 255)"  # Cor da legenda
    ),
    align="center"
)

# Exibir o gráfico
fig.show()
