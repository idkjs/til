open Printf;

let () = {
  let file = open_out("out_args.txt");
  let args =
    Array.to_list(Array.sub(Sys.argv, 1, Array.length(Sys.argv) - 1));
  printf("Write args to out_args.txt\n");
  List.iter(
    s => {
      printf("%s\n", s);
      fprintf(file, "%s\n", s);
    },
    args,
  );
  close_out_noerr(file);
};
