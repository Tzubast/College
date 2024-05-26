<template>
    <div v-if="submission.status">
        YES
    </div>
    <div v-else>
        NO
    </div>
</template>

<script setup>

const route = useRoute().params.id
const { data: request } = await useFetch(`http://localhost:5000/api/submissions/${route}`);
const submission = request._rawValue;
console.log(submission);

</script>