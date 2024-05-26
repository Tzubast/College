<template>
    <div v-if="accept.status">
        YES
    </div>
    <div v-else>
        NO
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