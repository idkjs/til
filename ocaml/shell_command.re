open Printf;

/* exec command and capture output */
let syscall = cmd => {
  let (in_ch, out_ch) = Unix.open_process(cmd);
  let buffer = Buffer.create(16);
  try(
    while (true) {
      Buffer.add_channel(buffer, in_ch, 1);
    }
  ) {
  | End_of_file => ()
  };
  ignore @@ Unix.close_process((in_ch, out_ch));
  Buffer.contents(buffer);
};

let () = {
  /* Sys.command return exit code */
  printf("%d\n", Sys.command("ls"));
  print_endline("Exec command and capture output");
  let output = syscall("date");
  print_endline("Output:");
  printf("%s\n", output);
};
