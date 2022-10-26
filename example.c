#include "./cpp-lib/c-bridge.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
  size_t N = 1024 * 1024;
  size_t OUTN = N * 1024;

  u_int32_t *data = malloc(N);

  for (int i = 0; i < N; i += 32) {
    data[i] = i;
  }

  const IntegerCODECPtr codec = CODECFactory_getFromName("simdfastpfor");

  u_int32_t *compressed = malloc(OUTN);
  size_t compressed_length = CODEC_encodeArray(codec, data, N, compressed);

  uint32_t *result = malloc(N);

  size_t written =
      CODEC_decodeArray(codec, compressed, compressed_length, result);

  for (int i = 0; i < N; i += 32) {
    if (data[i] != result[i]) {
      printf("what the fuck");
    }
  }
}
