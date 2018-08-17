randString <- function(n){
  return(paste0(sample(letters, n, replace = TRUE), collapse = ""))
}