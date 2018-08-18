source("optimizeDPI.R", encoding = "UTF-8")
dpi <- optimizeDPI("./dataR/test.pdf", "./results/results.csv")
write.csv(dpi, "./results/dpi.csv", row.names = FALSE)