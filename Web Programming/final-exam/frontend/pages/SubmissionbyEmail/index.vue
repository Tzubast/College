<template>
  <div class="bg-gradient-to-r from-blue-500 to-indigo-700 min-h-screen flex items-center justify-center">
    <div class="container max-w-sm max-h-md bg-blue-800 p-4 rounded-lg shadow-lg text-white">
      <form class="max-w-xs mx-auto" @submit.prevent="submitForm">
        <div class="mb-5">
          <label for="email" class="block mb-2 text-sm font-medium text-white">Get Your Status!</label>
          <input v-model="email" type="text" id="email" class="shadow-sm bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500 dark:shadow-sm-light" placeholder="xxxxxxxxxx@gmail.com" required>
        </div>
        <button type="submit" class="text-white bg-blue-700 hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 font-medium rounded-lg text-sm px-5 py-2.5 text-center dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">Go</button>
      </form>
    </div>
  </div>
</template>

<script setup>
import { useRouter } from 'vue-router';
import { ref } from 'vue';

const router = useRouter();
const email = ref('');

const submitForm = () => {
  if (email.value) {
    router.push(`/submissionbyemail/${encodeURIComponent(email.value)}`);
  }
}
</script>
