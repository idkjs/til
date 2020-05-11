open Printf;

let () =
  for (i in 0 to Array.length(Sys.argv) - 1) {
    printf("%i: %s\n", i, Sys.argv[i]);
  };
