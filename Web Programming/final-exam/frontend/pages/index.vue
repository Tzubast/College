<template>
   <div class="bg-gradient-to-r from-purple-400 to-indigo-600 min-h-screen flex items-center justify-center">
    <form class="max-w-xs mx-auto" @submit.prevent="submitForm">
        <div class="mb-5">
            <label for="name" class="block mb-2 text-sm font-medium text-white dark:text-gray-900">Nama</label>
            <input v-model="formData.name" type="text" id="name" class="shadow-sm bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500 dark:shadow-sm-light" placeholder="Isi nama" required>
        </div>
        <div class="mb-5">
            <label for="email" class="block mb-2 text-sm font-medium  text-white dark:text-gray-900">E-mail</label>
            <input v-model="formData.email" type="email" id="email" class="shadow-sm bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500 dark:shadow-sm-light" placeholder="xxxxxxxxxx@gmail.com" required>
        </div>
        <div class="mb-5">
            <label for="phone" class="block mb-2 text-sm font-medium  text-white dark:text-gray-900">Nomor Telepon</label>
            <input v-model="formData.phone" type="text" id="phone" class="shadow-sm bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500 dark:shadow-sm-light" placeholder="+62xxxxxxxx" required>
        </div>
        <div class="mb-5">
            <label for="institution" class="block mb-2 text-sm font-medium  text-white dark:text-gray-900">Universitas/Sekolah/Institut</label>
            <input v-model="formData.institution" type="text" id="institution" class="shadow-sm bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500 dark:shadow-sm-light" placeholder="Asal Universitas/Sekolah/Institut" required>
        </div>
        <button type="submit" class="text-white bg-gradient-to-r from-blue-600 to-blue-800 hover:from-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 font-medium rounded-lg text-sm px-5 py-2.5 text-center">
        Register
      </button>
    </form>
    <div v-if="isFormSubmitted">
      <p class="text-green-500">Sukses!</p>
    </div>
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