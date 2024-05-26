<template>
  <div class="bg-gradient-to-r from-blue-500 to-indigo-700 min-h-screen flex items-center justify-center">
    <div class="container max-w-md max-h-lg bg-blue-800 p-4 rounded-lg shadow-lg text-white">
      <div v-if="accept && accept.status === 'Accepted'" class="text-lg text-center p-5 font-semibold text-green-500">
        Selamat Bergabung
      </div>
      <div v-else-if="waiting && accept.status === 'Waiting'" class="text-lg text-center font-semibold p-5 text-yellow-500">
        Mohon tunggu konfirmasi
      </div>
      <div v-else class="text-lg text-center font-semibold p-5 text-red-500">
        Maaf, Silahkan Coba Lagi Di Tahun Depan
      </div>
    </div>
  </div>
</template>
<script setup>
const route = useRoute().params.email
const { data: request } = await useFetch('http://localhost:5000/api/submissions');
const submissions = request._rawValue.docs;

let accept;

submissions.forEach(submission => {
    console.log(submission.email);
    if (submission.email === route) {
        accept = submission;
    }
});

</script>
