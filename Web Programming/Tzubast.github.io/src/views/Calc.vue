<template>
  <div>
    <h1>Kalkulator Sederhana</h1>
    <h3>Nur Azka Rahadiansyah | 5027221064</h3>

    <input type="number" v-model.number="firstNumber" placeholder="Masukkan angka" />
    <input type="number" v-model.number="secondNumber" placeholder="Masukkan angka" />

    <br />
    <br />
    <br />

    <button @click="addition"><i class="fa fa-plus"></i></button>
    <button @click="subtraction"><i class="fa fa-minus"></i></button>
    <button @click="multiplication"><i class="fa fa-times"></i></button>
    <button @click="division"><i class="fa fa-divide"></i></button>

    <br />
    <br />

    <input v-model="result" readonly />
  </div>
</template>


<script>
export default {
  data() {
    return {
      firstNumber: '',
      secondNumber: '',
      result: ''
    }
  },
  methods: {
    addition() {
      this.result = this.firstNumber + this.secondNumber
    },
    subtraction() {
      this.result = this.firstNumber - this.secondNumber
    },
    multiplication() {
      this.result = this.firstNumber * this.secondNumber
    },
    division() {
      if (this.secondNumber !== 0) {
        this.result = this.firstNumber / this.secondNumber
      } else {
        this.result = 'Tidak dapat membagi dengan 0'
      }
    }
  }
}
</script>
