<template>
    <div class="container mx-auto self-center">
    <form class="max-w-sm mx-auto" @submit.prevent="submitForm">
        <div class="mb-5">
            <label for="name" class="block mb-2 text-sm font-medium text-white dark:text-gray-900">Your name</label>
            <input v-model="formData.name" type="text" id="name" class="shadow-sm bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500 dark:shadow-sm-light" placeholder="Cloud" required>
        </div>
        <div class="mb-5">
            <label for="email" class="block mb-2 text-sm font-medium  text-white dark:text-gray-900">Your email</label>
            <input v-model="formData.email" type="email" id="email" class="shadow-sm bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500 dark:shadow-sm-light" placeholder="cloud@soic.com" required>
        </div>
        <div class="mb-5">
            <label for="phone" class="block mb-2 text-sm font-medium  text-white dark:text-gray-900">Your phone number</label>
            <input v-model="formData.phone" type="text" id="phone" class="shadow-sm bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500 dark:shadow-sm-light" placeholder="+6289076543" required>
        </div>
        <div class="mb-5">
            <label for="institution" class="block mb-2 text-sm font-medium  text-white dark:text-gray-900">Your institution</label>
            <input v-model="formData.institution" type="text" id="institution" class="shadow-sm bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500 dark:shadow-sm-light" placeholder="UGM" required>
        </div>
        <button type="submit" class="text-white bg-blue-700 hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 font-medium rounded-lg text-sm px-5 py-2.5 text-center dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800">Register</button>
    </form>
    </div>
    <div v-if="isFormSubmitted">
      <p class="text-green-500">Form submitted successfully!</p>
    </div>
</template>
<script setup>
import { ref } from 'vue';

const formData = ref({
    name: '',
    email: '',
    phone: '',
    institution: '',
});

const isFormSubmitted = ref(false);

const submitForm = async () => {
  try {
    const response = await fetch('http://localhost:5000/api/submissions', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      credentials: 'include',
      body: JSON.stringify({
        name: formData.value.name,
        email: formData.value.email,
        phone: formData.value.phone,
        institution: formData.value.institution,
      }),
    });

    if (!response.ok) {
      throw new Error(`HTTP error! Status: ${response.status}`);
    }

    const responseData = await response.json();
    console.log(responseData);
    isFormSubmitted.value = true;
    formData.value = {
      name: '',
      email: '',
      phone: '',
      institution: '',
    };
  } catch (error) {
    console.error('Error submitting form:', error.message);
  }
};

</script>