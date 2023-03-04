# temp = np.array([[36.7, 29, ...], [...]])
# min_temp = 28
# max_temp = 40
# temp_norm = 255 * (temp - min_temp) / (max_temp - min_temp)
# temp_norm = temp_norm.astype(np.uint8)

# norm_temp = (temp - temp_min) / (temp_max - temp_min)

# log_temp = log(norm_temp + 1)
# exp_temp = exp(norm_temp)
# gray_temp = (log_temp / log_temp.max() * 255).astype(np.uint8)
# gray_

# color_map = cv2.COLORMAP_JET
# temp_normed = cv2.normalize(temp_data, None, 0, 255, cv2.NORM_MINMAX, dtype=cv2.CV_8U)
# temp_colored = cv2.applyColorMap(temp_norm, color_map)

for i in range(30):
    i=i+1
    x = 240/i
    y=180/i
    if x.is_integer() and y.is_integer():
        print(240/i,180/i)