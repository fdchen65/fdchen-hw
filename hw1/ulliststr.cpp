#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void ULListStr::push_back(const std::string& val){
  //if string is empty
  if(val.length() == 0){ return;}
  //special case, if empty, add block
  if(tail_ == NULL){
    Item* temp = new Item();
    tail_ = temp;
    head_ = temp;
  }
  for(unsigned i = 0; i < val.length() ; i++){
    //if need more space, make new empty block behind
    if(tail_->last == ARRSIZE){
      Item* temp = new Item();
      tail_->next = temp;
      temp->prev = tail_;
      tail_ = temp;
    }
    if(tail_->first == tail_->last){
      //empty block
      tail_->val[0] = val[i];
      tail_->last++;
    } else {
      //not empty block, not full block
      tail_->val[tail_->last] = val[i];
      tail_->last++;
    }
    size_++;
  }
}

void ULListStr::push_front(const std::string& val){
  //if string is empty
  if(val.length() == 0){ return;}
  //special case, if empty, add block
  if(tail_ == NULL){
    Item* temp = new Item();
    tail_ = temp;
    head_ = temp;
  }
  for(int i = val.length()-1 ; i >= 0; i--){
    if(head_->first == 0){
      //check to see if need to allocate another block in front
      Item* temp = new Item();
      temp->first = 0;
      temp->last = 0;
      temp->next = head_;
      head_->prev = temp;
      head_ = temp;
    }
    if(head_->first == head_->last){
      //for empty blocks
      head_->val[ARRSIZE-1] = val[i];
      head_->first = ARRSIZE-1;
      head_->last = ARRSIZE;
    } else {
      //no empty block, no full block
      head_->first--;
      head_->val[head_->first] = val[i];
    }
    size_++;
  }
}

void ULListStr::pop_back(){
  tail_->last--;
  //check to see if empty now
  if(tail_->last == tail_->first){
    Item* temp = tail_->prev;
    delete tail_;
    tail_ = temp;
    tail_->next = NULL;
  }
  size_--;
}

void ULListStr::pop_front(){
  head_->first++;
  //check to see if empty now
  if(tail_->first == tail_->last){
    Item* temp = tail_->next;
    delete head_;
    head_ = temp;
    head_->prev = NULL;
  }
  size_--;
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  //exceptions
  if(loc > size_ || loc < 0){
    return NULL;
  }
  Item* curr = head_;
  unsigned int cpy = loc;
  while(cpy >= curr->last - curr->first){
    cpy -= curr->last - curr->first;
    curr = curr->next;
  }
  return &(curr->val[curr->first + cpy]);
}