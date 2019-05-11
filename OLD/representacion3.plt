plot "poroso.dat" title "Poroso de longitud L=250, porosidad r=4" with points
set xlabel "Longitud"
set yrange [-0.5:1.5]
set ylabel "Valores"
set ytics 1
set terminal png
set output "poroso_250_4.png"
replot
