open Printf;
open Unix;

let remove_file = file => unlink(file);

let create_sample_file = filename => {
  let oc = open_out(filename);
  fprintf(oc, "%s", "Hello, World!");
  close_out(oc);
};

let () = {
  let filename = "sample_file.txt";
  create_sample_file(filename);
  remove_file(filename);
};
