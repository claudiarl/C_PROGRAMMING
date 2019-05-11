plot "poroso.dat" title "Poroso de longitud L=1250, porosidad r=0.25" with points
set xlabel "Longitud"
set xrange [0:1250]
set yrange [-0.5:1.5]
set ylabel "Valores"
set ytics 1
set terminal png
set output "poroso_1250_0.25.png"
replot
