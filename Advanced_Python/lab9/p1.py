import requests
import pandas as pd
import matplotlib.pyplot as plt
from requests.exceptions import HTTPError

def get_gold_price(year, start_end=None):
    if start_end is not None:
        date = start_end
    else:
        date = [f'{year}-01-01', f'{year}-12-31']   
    try:
        url = 'http://api.nbp.pl/api/cenyzlota/{0}/{1}'.format(date[0],date[1])
        response = requests.get(url).json()
    except HTTPError as http_error:
        print(f'HTTP error: {http_error}')
    else:
        df = pd.DataFrame(response)
    return df

def group_by_month(df):
    df['data'] = pd.to_datetime(df['data'])
    df_grouped = df.groupby(df['data'].dt.to_period("M")).mean()
    return df_grouped

def moving_average(df,future_steps=5, window_size = 3):
    future_steps = 5
    window_size = 4
    df['data'] = pd.to_datetime(df['data'])
    df.set_index('data', inplace=True)
    df_monthly = df.resample('M').mean() 
    df_monthly['moving_average'] = df_monthly['cena'].rolling(window=window_size).mean()
    last_observed_value = df_monthly['cena'].iloc[-1]
    for i in range(1, future_steps + 1):
        df_monthly.loc[df_monthly.index[-1] + pd.DateOffset(months=i), 'moving_average'] = last_observed_value
    return df_monthly

if __name__ == "__main__":
    df1 = group_by_month(get_gold_price(2021))
    df2 = group_by_month(get_gold_price(2022))
    df3 = group_by_month(get_gold_price(2023,['2023-01-01','2023-11-01']))
    df3_mean = df3['cena'].mean()

    df = pd.concat([df1,df2])
    df_pre = moving_average(df)
    df_pre_mean = df_pre[df_pre.index.year==2023].mean().astype(float)

    fig, axis = plt.subplots(2, 2, figsize=(12, 8))
    axis[0, 0].plot(df1.index.astype(str), df1['cena'], marker='o') 
    axis[0, 0].tick_params(axis='x', rotation=45)
    axis[0, 0].set_title("gold price - 2021")
    plt.tight_layout()
    
    axis[0, 1].plot(df2.index.astype(str), df2['cena'], marker='o') 
    axis[0, 1].tick_params(axis='x', rotation=45)
    axis[0, 1].set_title("gold price - 2022") 
    axis[0, 1].set_ylabel("zloty")
    plt.tight_layout()
    

    axis[1, 0].plot(df_pre.index.astype(str), df_pre['moving_average'], color='red', label=f'moving average')
    axis[1, 0].plot(df_pre.index.astype(str), df_pre['cena'], color='blue', label=f'true')
    axis[1, 0].tick_params(axis='x', rotation=45)
    axis[1, 0].set_title("gold price prediction - 2023") 
    axis[1, 0].set_ylabel("zloty")
    axis[1, 0].legend()
    
    axis[1, 1].plot(df3.index.astype(str), df3['cena'], marker='o') 
    axis[1, 1].axhline(y=df3_mean, color='blue', linestyle='--', label=f'true average:{df3_mean:.2f}')
    axis[1, 1].axhline(y=df_pre_mean['moving_average'], color='red', linestyle='--', label=f'prediction average')
    axis[1, 1].tick_params(axis='x', rotation=45)
    axis[1, 1].set_title("gold price - 2023 - avg(pre&true)") 
    axis[1, 1].set_ylabel("zloty")
    axis[1, 1].legend()

    plt.show()
