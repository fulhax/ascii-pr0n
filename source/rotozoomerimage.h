#ifndef __ROTOZOOMERIMAGE_H__
#define __ROTOZOOMERIMAGE_H__

#define IMAGEW 48
#define IMAGEH 48

static const struct
{
    unsigned int   width;
    unsigned int   height;
    unsigned int   bytes_per_pixel; /* 3:RGB, 4:RGBA */
    unsigned char  pixel_data[48 * 48 * 3 + 1];
} image =
{
    48, 48, 3,
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\13"
  "\217\332\13\217\332\13\217\332\13\217\332\13\217\332\13\217\332\13\217\332"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\13\217\332\13\217\332\353=6\353=6\353=6\353=6\353"
  "=6\353=6\353=6\13\217\332\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\13\217\332\353=6\353=6\353=6\353=6\353=6\353="
  "6\353=6\353=6\353=6\353=6\13\217\332\13\217\332y\230\265y\230\265y\230\265"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\13\217\332\353=6\353=6\353=6\353=6\353=6\353=6\353=6\361"
  "w8\361w8\361w8\361w8\361w8\361w8y\230\265\237\330\366\237\330\366y\230\265"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\13"
  "\217\332\353=6\353=6\353=6\353=6\361w8\361w8\361w8\361w8\361w8\361w8\361"
  "w8\361w8\361w8\361w8y\230\265\237\330\366\237\330\366y\230\265\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\13"
  "\217\332\13\217\332\361w8\361w8\361w8\361w8\361w8\361w8\361w8\363\361\200"
  "\363\361\200\363\361\200\13\217\332\13\217\332y\230\265\237\330\366d~\226"
  "\237\330\366y\230\265\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\13\217\332\361w8\361w8\361w8\361w8\361w8\363\361\200\363"
  "\361\200\363\361\200\363\361\200\13\217\332\13\217\332\237\330\366\237\330"
  "\366\237\330\366\237\330\366y\230\265\237\330\366y\230\265\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\13\217\332\361w8\361w8\361"
  "w8\361w8\363\361\200\363\361\200\363\361\200\363\361\200\363\361\200\13\217"
  "\332\237\330\366\237\330\366\237\330\366\237\330\366\237\330\366\237\330"
  "\366y\230\265\237\330\366y\230\265\13\217\332\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\13\217\332\361w8\361w8\361w8\363\361\200\363\361\200\363\361\200"
  "\363\361\200\363\361\200\363\361\200\13\217\332\0\0\0\0\0\0\0\0\0\237\330"
  "\366\237\330\366\237\330\366\237\330\366\237\330\366\237\330\366y\230\265"
  "\177\271A\13\217\332\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\13\217\332\363"
  "\361\200\363\361\200\363\361\200\363\361\200\363\361\200\363\361\200\13\217"
  "\332\13\217\332\0\0\0\0\0\0\273\6U\377\377\377\0\0\0\0\0\0\0\0\0\237\330"
  "\366\237\330\366\237\330\366y\230\265\177\271A\13\217\332\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\13\217\332\363\361\200\363\361\200\13\217\332\13\217\332\13"
  "\217\332\13\217\332\13\217\332\237\330\366\0\0\0\0\0\0\0\0\0\0\0\0\273\6"
  "U\377\377\377\237\330\366\237\330\366\237\330\366\237\330\366\237\330\366"
  "y\230\265\177\271A\177\271A\13\217\332\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\13\217\332\363"
  "\361\200\13\217\332\377\0\377\377\0\377\377\0\377y\230\265\237\330\366\237"
  "\330\366\0\0\0\0\0\0\377\377\377\0\0\0\273\6U\377\377\377\0\0\0\0\0\0\237"
  "\330\366\237\330\366\237\330\366\13\217\332\177\271A\177\271A\13\217\332"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\13\217\332\377\0\377\377\0\377\377\0\377\377"
  "\0\377y\230\265\237\330\366\237\330\366\0\0\0\0\0\0\0\0\0\0\0\0\313^\242"
  "\377\377\377\237\330\366\237\330\366\237\330\366\237\330\366\13\217\332\177"
  "\271A\177\271A\177\271A\13\217\332\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377y\230\265\237\330\366\237\330\366"
  "\0\0\0\377\377\377\0\0\0\0\0\0\377\273\332\377\377\377\237\330\366\237\330"
  "\366\237\330\366\13\217\332\177\271A\177\271A\177\271A\177\271A\13\217\332"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377y\230"
  "\265y\230\265\237\330\366\237\330\366\0\0\0\0\0\0\0\0\0\273\6U\377\377\377"
  "\237\330\366\237\330\366\237\330\366\13\217\332\177\271A\177\271A\177\271"
  "A\177\271A\177\271A\13\217\332\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377y\230\265\237\330\366d~\226\237\330\366\0\0\0\377"
  "\377\377\377\377\377\377\377\377\237\330\366\0\0\0\237\330\366\13\217\332"
  "\177\271A\177\271A\177\271A\177\271A\177\271A\13\217\332\13\217\332\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\13\217\332"
  "\13\217\332\13\217\332\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377y\230\265"
  "\237\330\366y\230\265\237\330\366\237\330\366\237\330\366\237\330\366\237"
  "\330\366\237\330\366\237\330\366\13\217\332\177\271A\13\217\332\177\271A"
  "\177\271A\177\271A\13\217\332\13\217\332\13\217\332\377\0\377\377\0\377\377"
  "\0\377\377\0\377\13\217\332\13\217\332\13\217\332p#\215p#\215p#\215\13\217"
  "\332\13\217\332\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377y\230\265y\230\265\237\330"
  "\366\237\330\366\237\330\366\237\330\366\237\330\366\237\330\366\13\217\332"
  "\177\271A\13\217\332\13\217\332\177\271A\13\217\332\13\217\332\13\217\332"
  "p#\215\13\217\332\377\0\377\377\0\377\377\0\377\13\217\332p#\215p#\215p#"
  "\215p#\215p#\215p#\215p#\215p#\215\13\217\332\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377y\230\265y\230\265y\230\265y\230\265y\230\265y\230\265\237"
  "\330\366\13\217\332\237\330\366\237\330\366\13\217\332\13\217\332\13\217"
  "\332p#\215p#\215\13\217\332\377\0\377\377\0\377\13\217\332p#\215p#\215p#"
  "\215p#\215p#\215p#\215p#\215p#\215p#\215p#\215\13\217\332\13\217\332\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377y\230"
  "\265\237\330\366\237\330\366\237\330\366\13\217\332\13\217\332\13\217\332"
  "\13\217\332p#\215p#\215\13\217\332y\230\265y\230\265y\230\265\13\217\332"
  "\13\217\332\13\217\332\13\217\332\13\217\332\13\217\332p#\215p#\215p#\215"
  "p#\215p#\215p#\215\13\217\332\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377y\230\265\237\330\366\237\330\366\237\330\366\13\217"
  "\332\13\217\332\13\217\332p#\215p#\215p#\215p#\215\13\217\332\237\330\366"
  "\237\330\366y\230\265\177\271A\177\271A\177\271A\177\271A\177\271A\13\217"
  "\332\13\217\332p#\215p#\215p#\215\13\217\332p#\215\13\217\332\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377y\230\265\237\330\366\237\330\366"
  "\13\217\332\13\217\332y\230\265\13\217\332p#\215p#\215p#\215p#\215\13\217"
  "\332y\230\265\237\330\366\237\330\366y\230\265\13\217\332\13\217\332\13\217"
  "\332\177\271A\177\271A\13\217\332\13\217\332p#\215\13\217\332\377\0\377\13"
  "\217\332\13\217\332\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "y\230\265\237\330\366\13\217\332\237\330\366y\230\265\237\330\366\13\217"
  "\332p#\215p#\215p#\215p#\215\13\217\332y\230\265\333\377\377\237\330\366"
  "y\230\265\377\0\377\377\0\377\377\0\377\13\217\332\177\271A\13\217\332\13"
  "\217\332\13\217\332\13\217\332\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377y\230\265\237\330\366\237\330\366"
  "\237\330\366y\230\265\237\330\366\237\330\366\13\217\332p#\215p#\215p#\215"
  "\13\217\332\333\377\377\333\377\377\333\377\377\237\330\366y\230\265\377"
  "\0\377\377\0\377\13\217\332\177\271A\177\271A\13\217\332\13\217\332\13\217"
  "\332\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377y\230\265\237\330\366\237\330\366y\230\265\237\330"
  "\366y\230\265\13\217\332p#\215p#\215\13\217\332\237\330\366\13\217\332\363"
  "\361\200\353=6\237\330\366y\230\265\377\0\377\377\0\377\13\217\332\363\361"
  "\200\177\271A\177\271A\13\217\332\13\217\332\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377y\230\265"
  "\237\330\366\237\330\366\237\330\366y\230\265y\230\265y\230\265\13\217\332"
  "p#\215\13\217\332\237\330\366\13\217\332\363\361\200\353=6\237\330\366y\230"
  "\265\377\0\377\377\0\377\13\217\332\363\361\200\177\271A\177\271A\13\217"
  "\332\13\217\332\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377y\230\265\237\330\366\237\330"
  "\366\237\330\366\237\330\366\237\330\366\237\330\366\13\217\332y\230\265"
  "\13\217\332\363\361\200\353=6\237\330\366\237\330\366y\230\265\377\0\377"
  "\377\0\377\13\217\332\361w8\363\361\200\177\271A\13\217\332\13\217\332\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377y\230\265y\230\265\237\330\366\237\330\366y\230"
  "\265\237\330\366\237\330\366\237\330\366y\230\265\237\330\366\237\330\366"
  "\237\330\366\237\330\366y\230\265\377\0\377\377\0\377\13\217\332\353=6\361"
  "w8\363\361\200\177\271A\177\271A\13\217\332\377\0\377\377\0\377\377\0\377"
  "\13\217\332\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377y\230\265y\230\265"
  "\237\330\366\237\330\366\237\330\366\237\330\366y\230\265y\230\265y\230\265"
  "y\230\265y\230\265y\230\265\237\330\366\237\330\366\237\330\366y\230\265"
  "\377\0\377\377\0\377\13\217\332\353=6\361w8\363\361\200\177\271A\177\271"
  "A\13\217\332\13\217\332\377\0\377\13\217\332\13\217\332\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377y\230\265\237\330\366\237\330\366\237\330\366\237"
  "\330\366y\230\265\221\277\343\221\277\343d~\226\377\0\377\377\0\377d~\226"
  "y\230\265\237\330\366\237\330\366y\230\265y\230\265\13\217\332\353=6\353"
  "=6\361w8\363\361\200\177\271A\177\271A\13\217\332\13\217\332\13\217\332\13"
  "\217\332\13\217\332\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377y\230\265"
  "\237\330\366\237\330\366y\230\265y\230\265d~\226\221\277\343\221\277\343"
  "d~\226\377\0\377\377\0\377\377\0\377d~\226y\230\265\237\330\366\237\330\366"
  "\237\330\366y\230\265\353=6\361w8\361w8\363\361\200\177\271A\177\271A\13"
  "\217\332\13\217\332\13\217\332\13\217\332\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377y\230\265\237\330\366y\230\265y\230\265\377\0\377d~\226"
  "\221\277\343\221\277\343\221\277\343d~\226\377\0\377\377\0\377\377\0\377"
  "y\230\265\237\330\366\237\330\366\237\330\366y\230\265\361w8\361w8\361w8"
  "\363\361\200\177\271A\177\271A\13\217\332\13\217\332\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377y\230\265\237\330\366"
  "\237\330\366y\230\265\377\0\377\377\0\377d~\226\221\277\343\221\277\343\221"
  "\277\343d~\226\377\0\377\377\0\377d~\226y\230\265\237\330\366\237\330\366"
  "y\230\265\13\217\332\361w8\361w8\363\361\200\177\271A\177\271A\177\271A\13"
  "\217\332\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377y\230\265\237\330\366\237\330\366\237\330\366y\230\265\377\0\377"
  "d~\226\221\277\343\221\277\343\221\277\343d~\226\377\0\377\377\0\377\377"
  "\0\377y\230\265\237\330\366\237\330\366y\230\265d~\226\13\217\332\361w8\363"
  "\361\200\177\271A\177\271A\177\271A\13\217\332\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377y\230\265\237\330\366\237\330"
  "\366\237\330\366\237\330\366y\230\265d~\226\221\277\343\221\277\343\221\277"
  "\343\221\277\343d~\226\377\0\377\377\0\377y\230\265\237\330\366\237\330\366"
  "\237\330\366y\230\265\377\0\377\13\217\332\363\361\200\363\361\200\177\271"
  "A\177\271A\13\217\332\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377y\230\265\237\330\366\237\330\366\237\330\366\237\330"
  "\366y\230\265d~\226\221\277\343\221\277\343\221\277\343\221\277\343d~\226"
  "\377\0\377\377\0\377y\230\265\237\330\366\237\330\366\237\330\366y\230\265"
  "\377\0\377\13\217\332\363\361\200\363\361\200\177\271A\177\271A\177\271A"
  "\13\217\332\13\217\332\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377y\230\265\237\330\366\237\330\366\237\330\366y\230\265\377\0\377d~\226"
  "\221\277\343\221\277\343\221\277\343\221\277\343d~\226\377\0\377\377\0\377"
  "y\230\265\237\330\366\237\330\366\237\330\366y\230\265\377\0\377\377\0\377"
  "\13\217\332\363\361\200\363\361\200\177\271A\177\271A\177\271A\177\271A\13"
  "\217\332\13\217\332\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377y\230\265"
  "\237\330\366\237\330\366y\230\265\377\0\377d~\226\221\277\343\221\277\343"
  "\221\277\343\221\277\343d~\226\377\0\377\377\0\377y\230\265\237\330\366\237"
  "\330\366\237\330\366y\230\265\377\0\377\377\0\377\377\0\377\13\217\332\13"
  "\217\332\363\361\200\363\361\200\177\271A\13\217\332\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377y\230\265\237\330\366y\230\265"
  "\377\0\377\377\0\377d~\226\221\277\343\221\277\343\221\277\343\221\277\343"
  "d~\226\377\0\377\377\0\377y\230\265\237\330\366\237\330\366\237\330\366\237"
  "\330\366y\230\265\377\0\377\377\0\377\377\0\377\377\0\377\13\217\332\13\217"
  "\332\13\217\332\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377y\230\265y\230\265\377\0\377\377\0\377d~\226\221"
  "\277\343\221\277\343\221\277\343\221\277\343d~\226\377\0\377\377\0\377y\230"
  "\265\237\330\366\237\330\366\237\330\366\237\330\366y\230\265\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377d~\226d~\226d~\226d~\226d~\226\377\0\377"
  "\377\0\377\377\0\377y\230\265\237\330\366\237\330\366\237\330\366\237\330"
  "\366y\230\265\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377y\230\265"
  "y\230\265y\230\265y\230\265y\230\265y\230\265\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0"
  "\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377"
  "\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377"
  "\0\377\377\0\377\377\0\377\377\0\377\377\0\377\377\0\377",
};

#endif //__ROTOZOOMERIMAGE_H__
