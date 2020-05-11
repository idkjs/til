open Core;

/** write to file **/

let file_write = (filename, str) => {
  let oc = Out_channel.create(filename);
  protect(
    ~f=() => fprintf(oc, "%s\n", str),
    ~finally=() => Out_channel.close(oc),
  );
};

let file_append = (filename, str) => {
  let oc = Out_channel.create(~append=true, filename);
  protect(
    ~f=() => fprintf(oc, "%s\n", str),
    ~finally=() => Out_channel.close(oc),
  );
};

let () = {
  file_write("sample.txt", "Hello, World!");
  file_append("sample.txt", "Hello, OCaml!");
};
