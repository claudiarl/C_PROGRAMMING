plot  "Ej4_1024.dat" title "L=1024" with linespoints,\
"Ej4_32.dat" title "L=32" with linespoints
set xlabel "Porosidad"
set xrange [0:9]
set ylabel "Longitud correlación"
set yrange [0:18]
set terminal png
set output "long_correl_ej4.png"
replot
