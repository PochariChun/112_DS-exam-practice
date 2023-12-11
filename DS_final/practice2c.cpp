// 題目內容
// 腸功王國共有 3! 座城市。每座城市由 3 個數字組成，它們是由 1 2 3 的
// 排列組合。腸功王國的城堡位於 1 2 3 的城市中。a1 a2 a3 和 b1 b2 b3 分別是城
// 市 A 和城市 B 的編碼，在王國的 A 和 B 之間修建了一條距離為 1 的道路，
// 且僅當存在一個 i (1 ≤ i < 3），且滿足以下兩個條件時，該道路才會被修建。
// 1. ai = bi+1 and ai+1 = bi;
// 2. aj = bj for j ∈ {1, 2, 3}\{i, i + 1}
// 有一天，國王邀請所有市長到城堡開會。請幫市長們計算他們到城堡的路程。
// 請注意，城堡所在城市的編碼為 1 2 3 。
// 舉下圖為例：王國共有 6 座城市，即 n 值為 3。每座城市都以 1 2 3 的排
// 列編碼。