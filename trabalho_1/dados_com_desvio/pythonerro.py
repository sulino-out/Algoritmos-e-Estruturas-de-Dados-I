# --- 1. Importação das Bibliotecas ---
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.ticker as mticker
import io

# --- 2. Leitura e Combinação dos Dados ---
try:
    # Aplicando um estilo visual profissional
    plt.style.use('seaborn-v0_8-whitegrid')
    plt.rcParams.update({'font.size': 12})

    # Seus 5 conjuntos de dados em formato de texto
    csv_data1 = """Funcao,Tamanho,Segundos,Nano Segundos
inverter, 10, 0, 000000084
inverter, 100, 0, 000000506
inverter, 1000, 0, 000005199
inverter, 5000, 0, 000031159
Busca_Sequencial, 10, 0, 000000015
Busca_Sequencial, 100, 0, 000000016
Busca_Sequencial, 1000, 0, 000000020
Busca_Sequencial, 5000, 0, 000000023
Busca Binaria Recursiva, 10, 0, 000000026
Busca Binaria Recursiva, 100, 0, 000000039
Busca Binaria Recursiva, 1000, 0, 000000045
Busca Binaria Recursiva, 5000, 0, 000000039
Busca Binaria Iterativa, 10, 0, 000000020
Busca Binaria Iterativa, 100, 0, 000000040
Busca Binaria Iterativa, 1000, 0, 000000045
Busca Binaria Iterativa, 5000, 0, 000000045"""

    csv_data2 = """Funcao,Tamanho,Segundos,Nano Segundos
inverter, 10, 0, 000000076
inverter, 100, 0, 000000470
inverter, 1000, 0, 000008160
inverter, 5000, 0, 000055875
Busca_Sequencial, 10, 0, 000000036
Busca_Sequencial, 100, 0, 000000037
Busca_Sequencial, 1000, 0, 000000037
Busca_Sequencial, 5000, 0, 000000046
Busca Binaria Recursiva, 10, 0, 000000048
Busca Binaria Recursiva, 100, 0, 000000059
Busca Binaria Recursiva, 1000, 0, 000000069
Busca Binaria Recursiva, 5000, 0, 000000105
Busca Binaria Iterativa, 10, 0, 000000056
Busca Binaria Iterativa, 100, 0, 000000096
Busca Binaria Iterativa, 1000, 0, 000000123
Busca Binaria Iterativa, 5000, 0, 000000092"""

    csv_data3 = """Funcao,Tamanho,Segundos,Nano Segundos
inverter, 10, 0, 000000075
inverter, 100, 0, 000000543
inverter, 1000, 0, 000005398
inverter, 5000, 0, 000039579
Busca_Sequencial, 10, 0, 000000042
Busca_Sequencial, 100, 0, 000000043
Busca_Sequencial, 1000, 0, 000000054
Busca_Sequencial, 5000, 0, 000000064
Busca Binaria Recursiva, 10, 0, 000000059
Busca Binaria Recursiva, 100, 0, 000000071
Busca Binaria Recursiva, 1000, 0, 000000085
Busca Binaria Recursiva, 5000, 0, 000000102
Busca Binaria Iterativa, 10, 0, 000000052
Busca Binaria Iterativa, 100, 0, 000000105
Busca Binaria Iterativa, 1000, 0, 000000093
Busca Binaria Iterativa, 5000, 0, 000000100"""

    csv_data4 = """Funcao,Tamanho,Segundos,Nano Segundos
inverter, 10, 0, 000000071
inverter, 100, 0, 000000476
inverter, 1000, 0, 000004743
inverter, 5000, 0, 000032791
Busca_Sequencial, 10, 0, 000000036
Busca_Sequencial, 100, 0, 000000037
Busca_Sequencial, 1000, 0, 000000046
Busca_Sequencial, 5000, 0, 000000053
Busca Binaria Recursiva, 10, 0, 000000051
Busca Binaria Recursiva, 100, 0, 000000063
Busca Binaria Recursiva, 1000, 0, 000000074
Busca Binaria Recursiva, 5000, 0, 000000095
Busca Binaria Iterativa, 10, 0, 000000049
Busca Binaria Iterativa, 100, 0, 000000074
Busca Binaria Iterativa, 1000, 0, 000000074
Busca Binaria Iterativa, 5000, 0, 000000088"""

    csv_data5 = """Funcao,Tamanho,Segundos,Nano Segundos
inverter, 10, 0, 000000094
inverter, 100, 0, 000000579
inverter, 1000, 0, 000009094
inverter, 5000, 0, 000041013
Busca_Sequencial, 10, 0, 000000044
Busca_Sequencial, 100, 0, 000000046
Busca_Sequencial, 1000, 0, 000000057
Busca_Sequencial, 5000, 0, 000000064
Busca Binaria Recursiva, 10, 0, 000000070
Busca Binaria Recursiva, 100, 0, 000000108
Busca Binaria Recursiva, 1000, 0, 000000111
Busca Binaria Recursiva, 5000, 0, 000000135
Busca Binaria Iterativa, 10, 0, 000000059
Busca Binaria Iterativa, 100, 0, 000000100
Busca Binaria Iterativa, 1000, 0, 000000102
Busca Binaria Iterativa, 5000, 0, 000000110"""
    
    all_csvs = [csv_data1, csv_data2, csv_data3, csv_data4, csv_data5]
    df_list = [pd.read_csv(io.StringIO(csv)) for csv in all_csvs]
    
    # Concatena todos os DataFrames em um só
    df = pd.concat(df_list, ignore_index=True)

    # Limpeza dos dados combinados
    df.columns = df.columns.str.strip()
    df['Nano Segundos'] = df['Nano Segundos'].astype(str).str.strip().astype(int)

    # --- 3. Cálculo da Média e Desvio Padrão ---
    # Agrupa os dados por Função e Tamanho, e calcula a média e o desvio padrão (std)
    stats_df = df.groupby(['Funcao', 'Tamanho'])['Nano Segundos'].agg(['mean', 'std']).reset_index()
    # Preenche std nulos com 0 (caso de haver apenas uma amostra)
    stats_df['std'] = stats_df['std'].fillna(0)

    # --- 4. Definições de Estilo ---
    style_map = {
        'inverter': {'color': '#1f77b4', 'marker': 'o'},
        'Busca_Sequencial': {'color': '#ff7f0e', 'marker': 'X'},
        'Busca Binaria Iterativa': {'color': '#2ca02c', 'marker': 's'},
        'Busca Binaria Recursiva': {'color': '#d62728', 'marker': '^'}
    }
    
    # --- 5. Geração dos Gráficos Individuais com Barras de Erro ---
    print("Gerando gráficos individuais com barras de erro...")
    funcoes_unicas = stats_df['Funcao'].unique()

    for funcao in funcoes_unicas:
        df_funcao_stats = stats_df[stats_df['Funcao'] == funcao]
        
        fig, ax = plt.subplots(figsize=(10, 7))
        
        cor = style_map.get(funcao, {}).get('color', 'blue')
        marcador = style_map.get(funcao, {}).get('marker', 'o')

        # !!! MUDANÇA: Usando ax.errorbar para plotar média com desvio padrão !!!
        ax.errorbar(x='Tamanho', y='mean', yerr='std', data=df_funcao_stats,
                     marker=marcador, linestyle='-', color=cor, markersize=8, capsize=5, label='Média e Desvio Padrão')
        
        ax.set_xscale('log')
        ax.xaxis.set_major_formatter(mticker.ScalarFormatter())
        ax.set_xticks(df['Tamanho'].unique())

        ax.set_title(f'Desempenho da Função: {funcao}', fontsize=16)
        ax.set_xlabel('Tamanho da Entrada (Escala Log)', fontsize=12)
        ax.set_ylabel('Tempo de Execução Médio (Nano Segundos)', fontsize=12)
        ax.grid(True, which="both", ls="-", linewidth=0.5)
        ax.legend()
        
        nome_arquivo = f'grafico_{funcao.replace(" ", "_")}_erro.png'
        plt.savefig(nome_arquivo, bbox_inches='tight')
        print(f"Gráfico '{nome_arquivo}' salvo.")
        plt.close(fig)

    # --- 6. Geração do Gráfico Comparativo com Subplots e Barras de Erro ---
    print("\nGerando gráfico comparativo com barras de erro...")
    fig, axes = plt.subplots(2, 1, figsize=(12, 10), sharex=True)

    # Gráfico Superior (Inverter)
    ax1 = axes[0]
    df_inverter_stats = stats_df[stats_df['Funcao'] == 'inverter']
    estilo_inverter = style_map['inverter']
    ax1.errorbar(x='Tamanho', y='mean', yerr='std', data=df_inverter_stats,
                 marker=estilo_inverter.get('marker'), color=estilo_inverter.get('color'),
                 linestyle='-', markersize=8, capsize=5, label='inverter')
    ax1.set_title('Comparação de Desempenho (Média e Desvio Padrão)', fontsize=16, pad=20)
    ax1.set_ylabel('Tempo Médio (ns) - Inverter')
    ax1.legend()
    ax1.grid(True, which="both", ls="-", linewidth=0.5)

    # Gráfico Inferior (Buscas)
    ax2 = axes[1]
    funcoes_busca = ['Busca_Sequencial', 'Busca Binaria Iterativa', 'Busca Binaria Recursiva']
    for funcao in funcoes_busca:
        df_funcao_stats = stats_df[stats_df['Funcao'] == funcao]
        estilo = style_map.get(funcao, {})
        ax2.errorbar(x='Tamanho', y='mean', yerr='std', data=df_funcao_stats,
                     marker=estilo.get('marker'), color=estilo.get('color'),
                     linestyle='-', markersize=8, capsize=5, label=funcao)
    ax2.set_ylabel('Tempo Médio (ns) - Funções de Busca')
    ax2.legend()
    ax2.grid(True, which="both", ls="-", linewidth=0.5)

    # Configurações do Eixo X compartilhado
    plt.xscale('log')
    ax2.xaxis.set_major_formatter(mticker.ScalarFormatter())
    ax2.set_xticks(df['Tamanho'].unique())
    plt.xlabel('Tamanho da Entrada (Escala Log)', fontsize=12)
    plt.tight_layout(rect=[0, 0, 1, 0.96])
    
    nome_arquivo_comp = 'grafico_comparativo_erro.png'
    plt.savefig(nome_arquivo_comp, bbox_inches='tight')
    print(f"Gráfico '{nome_arquivo_comp}' salvo.")
    plt.close()

    print("\nProcesso finalizado com sucesso!")

except FileNotFoundError:
    print("Erro: O arquivo 'dados.csv' não foi encontrado. Este script espera os dados no código, não em um arquivo.")
except Exception as e:
    print(f"Ocorreu um erro inesperado: {e}")