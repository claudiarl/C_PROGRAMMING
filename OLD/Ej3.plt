plot  "Ej3_1024.dat" title "Longitud de correlación en función de r. L=1024" with linespoints
set xlabel "Porosidad r"
set xrange [0:9]
set ylabel "Longitud correlación"
set yrange [0:0.27]
set terminal png
set output "long_correl_1024.png"
replot
