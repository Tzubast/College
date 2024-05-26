import { CollectionConfig } from "payload/types";

const Submissions: CollectionConfig = {
    slug: 'submissions',
    access : {
      read : () => true,
      update : () => true,
      delete : () => true,
      create : () => true
    },
    admin: {
      useAsTitle: 'name',
    },
    fields: [
      {
        name: 'name',
        type: 'text',
        label: 'Name',
        required: true
      },
      {
        name: 'email',
        type: 'email',
        label: 'Email Address',
        required: true
      },
      {
        name: 'phone',
        type: 'text',
        label: 'Phone Number',
        required: true
      },
      {
        name: 'institution',
        type: 'text',
        label: 'Institution',
        required: true
      },
      {
  name: 'status',
  type: 'select',
  label: 'Status',
  options: [
    { label: 'Waiting', value: 'waiting' },
    { label: 'Rejected', value: 'rejected' },
    { label: 'Accepted', value: 'accepted' }
  ],
  defaultValue: 'waiting' // Memilih 'Waiting' sebagai nilai default
}
    ],
  }
  
  export default Submissions