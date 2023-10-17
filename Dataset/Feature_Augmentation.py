import pandas as pd
import numpy as np

with_chewing_data = pd.read_csv('with_chewing.csv')
without_chewing_data = pd.read_csv('without_chewing.csv')
combined_data = pd.concat([with_chewing_data, without_chewing_data], keys=['chewing', 'not_chewing'])

def augment_features(data):
    data['Magnitude'] = np.sqrt(data['X']**2 + data['Y']**2 + data['Z']**2)
    return data


combined_data = combined_data.groupby(level=0).apply(augment_features)
with_chewing_augmented = combined_data.xs('chewing', level=0)
without_chewing_augmented = combined_data.xs('not_chewing', level=0)
with_chewing_augmented.to_csv('with_chewing_augmented.csv', index=False)
without_chewing_augmented.to_csv('without_chewing_augmented.csv', index=False)
